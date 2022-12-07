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
int a[5];
int main()
{
	memset(a,0,sizeof(a));
	int n;
	string s;
	cin>>n;cin>>s;
	lint out=1,mo=1000000007,t;
	rep(i,n){
		if(s[i]=='A') a[0]++;
		if(s[i]=='G') a[1]++;
		if(s[i]=='T') a[2]++;
		if(s[i]=='C') a[3]++;
	}
	sort(a,a+4);reverse(a,a+4);
	rep(i,4){
		if(a[i]==a[0]) t=i+1;
	}
	rep(i,n) out=(out*t)%mo;
	cout<<out<<endl;
}