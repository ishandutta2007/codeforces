#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<int> v[(1<<15)+10];
int bi[20];
int k;
void rec(int num,int mask,int pos){
	if(pos<0){v[mask].pb(num);return;}
	rec(num,mask,pos-1);
	while(1){
		num*=prime[pos];if(num>=2*k*k) break;rec(num,mask+(1<<pos),pos-1);
	}
	return;
}
int main()
{
	cin>>k;
	REP(i,2,16){
		rep(j,(1<<i)) v[j].clear();//cout<<i<<endl;
		rec(1,0,i-1);
		int f=0;vector <int> ret;
		/*if(i==2){
			rep(j,(1<<i)) rep(l,v[j].size()) cout<<j<<' '<<v[j][l]<<endl;
		}*/
		rep(j,(1<<i)) f+=v[j].size();if(f<k) continue;f=k;
		memset(bi,0,sizeof(bi));
		for(int j=(1<<i)-1;j>=0;j--){
			int nex=min((int)v[j].size(),f);f-=nex;
			rep(l,nex) ret.pb(v[j][l]);
			rep(l,i){
				if((j&(1<<l))) bi[l]+=nex;
			}
		}
		f=0;
		rep(j,i){
			if(bi[j]<(k+1)/2) f=1;
		}
		if(f>0) continue;sort(All(ret));//cout<<i<<endl;
		rep(j,k){
			cout<<ret[j];if(j<k-1) cout<<' ';else cout<<endl;
		}
		break;
	}
}