#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int q[110],rq[110],now[110],next[110],s[110];
bool fit[110],rfit[110];
int main()
{
	int i,n,k,j;
	memset(fit,false,sizeof(fit));memset(rfit,false,sizeof(rfit));
	cin>>n>>k;
	rep(i,n){
		cin>>q[i+1];rq[q[i+1]]=i+1;
	}
	//rep(i,n) cout<<q[i+1]<<' '<<rq[i+1]<<endl;
	rep(i,n) cin>>s[i+1];s[0]=0;
	rep(i,n+1) now[i]=i;
	rep(j,k+1){
		int f=0;
		rep(i,n){if(now[i+1]!=s[i+1]) f=1;}
		//cout<<i<<' '<<f<<endl;
		//if(f==0 && (k-j)%2==0){cout<<"YES"<<endl;return 0;}
		if(f<1) fit[j]=true;
		rep(i,n) next[q[i+1]]=now[i+1];
		rep(i,n) now[i+1]=next[i+1];
	}
	rep(i,n+1) now[i]=i;
	rep(j,k+1){
		int f=0;
		rep(i,n){if(now[i+1]!=s[i+1]) f=1;}
		//rep(i,n) cout<<now[i+1]<<endl;
		//if(f==0 && (k-j)%2==0){cout<<"YES"<<endl;return 0;}
		if(f<1) rfit[j]=true;
		rep(i,n) next[rq[i+1]]=now[i+1];
		rep(i,n) now[i+1]=next[i+1];
	}
	if(fit[0]){cout<<"NO"<<endl;return 0;}
	if((fit[1] && rfit[1])){
		if(k==1){cout<<"YES"<<endl;return 0;}
		else{cout<<"NO"<<endl;return 0;}
	}
	rep(i,k+1){
		if((k-i)%2==0 && (rfit[i] || fit[i])){cout<<"YES"<<endl;return 0;}
	}
	cout<<"NO"<<endl;
	return 0;
}