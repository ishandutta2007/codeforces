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
int a[110000],ne[110000];
bool sumi[110000];
vector <int> now,next;
int main()
{
	int n,out=0,it=0;
	cin>>n;rep(i,n) cin>>a[i];//a[n]=0;
	rep(i,n) ne[i]=i+1;
	rep(i,n) now.pb(n-i-1);
	memset(sumi,false,sizeof(sumi));
	for(int i=0;;i++){
		//cerr<<i<<'a'<<endl;
		next.clear();int m=now.size(),f=0;
		rep(j,m){
			int t=now[j];if(sumi[t]) continue;
			//cerr<<t<<endl;
			if(ne[t]>=n) continue;
			if(a[t]>a[ne[t]]){
				next.pb(t);f=1;sumi[ne[t]]=true;ne[t]=ne[ne[t]];
			}
		}
		if(f<1){
			cout<<i<<endl;break;
		}
		now=next;
	}
	return 0;
}