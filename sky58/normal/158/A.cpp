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
vector <int> a;
int main()
{
	int i,n,k,out=0,x;
	cin>>n>>k;
	rep(i,n){
		scanf("%d",&x);a.pb(x);
	}
	sort(All(a));reverse(All(a));
	rep(i,n){
		if(a[i]>0 && a[i]>=a[k-1]) out++;
	}
	cout<<out<<endl;
	return 0;
}