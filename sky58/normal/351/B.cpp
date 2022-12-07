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
int a[3100];
int main()
{
	int out=0,n;
	cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n) a[i]--;
	rep(i,n){
		rep(j,n){
			if(a[j]>i) out++;
			if(a[j]==i) break;
		}
	}
	cout<<(out/2)*4+(out%2)<<".0000000"<<endl;
	return 0;
}