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
int a[110][110];int b[110],out[110];
int main()
{
	memset(out,0,sizeof(out));
	int i,j,k,n;cin>>n;
	rep(i,n) rep(j,n) cin>>a[i][j];
	rep(i,31){
		memset(b,0,sizeof(b));
		rep(j,n) rep(k,n){
			if(j!=k){
				if((a[j][k]&(1<<i))) b[j]=b[k]=1;
			}
		}
		rep(j,n) out[j]+=b[j]<<i;
	}
	rep(i,n){
		cout<<out[i];if(i<n-1) cout<<" ";
	}
	cout<<endl;
	return 0;
}