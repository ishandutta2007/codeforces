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
#define N 1000010
int a[N+10],sum[N+10];
int main()
{
	int n,k,out=0,x;
	cin>>n>>k;
	rep(i,n){
		scanf("%d",&x);a[x]++;//cout<<x<<endl;
	}
	rep(i,N) sum[i+1]=sum[i]+a[i];
	REP(i,1,N){
		int t=0,len=min(k+1,i);
		for(int j=i;j<N;j+=i) t+=sum[min(N,j+len)]-sum[j];
		if(t==n) out=max(out,i);
	}
	cout<<out<<endl;
}