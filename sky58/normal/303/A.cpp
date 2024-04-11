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
typedef pair<pint,pint> fint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	int n;
	cin>>n;
	if(n%2==0){
		cout<<"-1"<<endl;return 0;
	}
	rep(i,n){
		printf("%d",i);
		if(i<n-1) printf(" ");else printf("\n");
	}
	rep(i,n){
		printf("%d",i);
		if(i<n-1) printf(" ");else printf("\n");
	}
	rep(i,n){
		printf("%d",(i*2)%n);
		if(i<n-1) printf(" ");else printf("\n");
	}
	return 0;
}