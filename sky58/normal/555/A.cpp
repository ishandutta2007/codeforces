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
int main()
{
	int n,m,a,b,comp=0;
	scanf("%d %d",&n,&m);
	rep(i,m){
		scanf("%d",&a);
		int pre=0,boa=a;
		rep(j,a){
			scanf("%d",&b);
			if(b>pre+1) boa=min(boa,j);
			pre=b;
		}
		if(boa<2) comp+=a;
		else comp+=a+1-boa;
	}
	cout<<(comp-m)+(comp-1)<<endl;
}