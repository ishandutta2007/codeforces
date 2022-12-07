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
int main()
{
	int i,n,a;vector <int> out;
	cin>>n;
	rep(i,n){
		scanf("%d",&a);out.pb(a);
	}
	sort(All(out));
	if(out[n-1]==1) out[n-1]=2;else out[n-1]=1;
	sort(All(out));
	rep(i,n){
		printf("%d",out[i]);if(i<n-1) printf(" ");
	}
	cout<<endl;
	return 0;
}