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
	lint n,a,su=0;vector <lint> b;
	cin>>n;
	rep(i,n){
		cin>>a;b.pb(a);su+=a;
	}
	sort(All(b));
	/*rep(i,n-1){
		su+=b[n-1]-b[i];//cout<<su<<endl;
		if(su>=b[n-1]){
			cout<<b[n-1]<<endl;return 0;
		}
	}
	cout<<b[n-1]+1<<endl;*/
	cout<<max(b[n-1],(su-1)/(n-1)+1)<<endl;
	return 0;
}