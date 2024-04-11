#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define mid ((l+r)>>1)
int n,k,vis[MN],ans;
int TOT=0;
void chk(vector<int>&p,int pos){
	for(int j=0;j<p.size();++j){	
		int i=p[j];
		cout<<"? "<<i<<endl;
		TOT++;
		char c;cin>>c;
		if(c=='Y'&&j>=pos)vis[i]=1;
	}
}
void solve(){
	//	solve(l,mid);
	//	solve(mid+1,r);
	//	TOT+=(r-mid)/k*(mid-l+1)/k*(4*k);
	//	return;
	//	cerr<<"done"<<endl;
	int cnt=0;
	for(int len=k;len<=n;len+=k){
		vector<int>p(0);
		for(int i=1;i<=len;i+=k){
			int j=i+len;
			if(j+k-1>n)continue;
			vector<int>p(0);
			for(int j=i;j<i+k;++j)p.push_back(j);
			chk(p,0);
			for(int j=i+len;j+k-1<=n;j+=len){
				p.clear();
				cnt++;
				for(int l=j;l<j+k;++l)p.push_back(l);
				chk(p,0);
			}
			cout<<"R"<<endl;
		}
	}
//	cerr<<"cnt: "<<cnt<<endl;
}
signed main(){
//	freopen("fk.in","r",stdin);
	ans=n=read();k=read();
	k=(k+1)>>1;
	solve();
//	cerr<<"TOT: "<<TOT<<endl;
	for(int i=1;i<=n;++i)if(vis[i])ans--;
	cout<<"! "<<ans<<endl;
//	cerr<<"TOT: "<<TOT<<endl;
	return 0;
}