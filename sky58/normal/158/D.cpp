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
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int sum[300][21000];
int main()
{
	int i,j,m,n,a,out=-1000000000;
	vector <int> ya;
	rep(i,300) rep(j,21000) sum[i][j]=0;
	cin>>n;
	REP(i,1,n+1){
		if(n%i==0 && n/i>2) ya.pb(i);
	}
	m=ya.size();
	rep(i,n){
		scanf("%d",&a);//cout<<a<<endl;
		rep(j,m) sum[j][i%ya[j]]+=a;
	}
	rep(i,m) rep(j,ya[i]) out=max(out,sum[i][j]);
	cout<<out<<endl;return 0;
}