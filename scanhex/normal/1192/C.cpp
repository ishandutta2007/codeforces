#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>
#include<map>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=100100;
const int mod=998244353;

int cnt=0;
map<char,int>mp;
const int C=64;
int c[C][C];

int ind(char ch){
	if(!mp.count(ch))mp[ch]=cnt++;
	return mp[ch];
}

void ad(int&x,int y){
	 if((x+=y)>=mod)x-=mod;
}
int mu(int a,int b){
	 return(nagai)a*b%mod;
}
int ord[]={7,3,5,6,0,1,2,4};
int ordinv[8];
int curans=1;
int ans=0;
int cur[8];
int prec[C][C][C];
void init(){
	for(int i=0;i<8;++i)
		ordinv[ord[i]]=i;
	memset(prec,0,sizeof prec);
	for(int x=0;x<cnt;++x)
		for(int y=0;y<=x;++y)
			for(int z=0;z<=y;++z){
				for(int lt=0;lt<cnt;++lt){
					ad(prec[x][y][z],mu(c[lt][x],mu(c[lt][y],c[lt][z])));
				}
				prec[y][z][x]=prec[z][y][x]=prec[x][z][y]=prec[y][x][z]=prec[z][x][y]=prec[x][y][z];
			}
}
int kekos[C][C][C];
void gen(int x){
	if(x==4){
		ad(kekos[cur[3]][cur[5]][cur[6]],curans);
	}
	else{
		int lim=x>1?cur[ord[x-1]]:cnt-1;
//		int lim=cnt-1;
		for(int lt=0;lt<=lim;++lt){
			int cn=1;
			for(int b=0;b<3;++b){
				int y=ord[x]^1<<b;
				if(ordinv[y]<x)cn=mu(cn,c[cur[y]][lt]);
			}
			if(cn){
				int w=curans;
				curans=mu(curans,cn);
				cur[ord[x]]=lt;
				gen(x+1);
				curans=w;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<string>v;
	for(int i=0;i<n;++i){
		 string s;
//		 for(int j=0;j<3;++j)
//			 s.push_back('A'+rand()%62);
		 cin>>s;
		 v.push_back(s);
		 reverse(s.begin(),s.end());
		 v.push_back(s);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int len=3;len<=10;++len){
		memset(c,0,sizeof c);
		for(auto x:v){
			if(x.size()==len)
				++c[ind(x.front())][ind(x.back())];
		}
		memset(kekos,0,sizeof kekos);
		init();
		gen(0);
		for(int x=0;x<cnt;++x)
			for(int y=0;y<=x;++y)
				for(int z=0;z<=y;++z)
					kekos[x][z][y]=kekos[y][x][z]=kekos[y][z][x]=kekos[z][x][y]=kekos[z][y][x]=kekos[x][y][z];
		for(cur[3]=0;cur[3]<cnt;++cur[3])
			for(cur[5]=0;cur[5]<=cur[3];++cur[5])
				for(cur[6]=0;cur[6]<=cur[5];++cur[6]){
					int k=kekos[cur[3]][cur[5]][cur[6]];
					if(!k)continue;
					int rofl=0;
					for(cur[0]=0;cur[0]<cnt;++cur[0]){
						int curans=k;
						for(int i=5;i<8;++i){
							curans=mu(curans,prec[cur[ord[i]^1]][cur[ord[i]^2]][cur[ord[i]^4]]);
						}
						ad(rofl,curans);
					}
					int mult=cur[3]==cur[6]?1:(cur[3]==cur[5]||cur[5]==cur[6])?3:6;
//					cerr<<cur[3]<<' '<<cur[5]<<' '<<cur[6]<<' '<<rofl<<' '<<mult<<'\n';
//					mult=1;
					ad(ans,mu(rofl,mult));
				}
	}
	cout<<ans<<'\n';
	return 0;
}