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
int a[510000];
int main()
{
	int n;cin>>n;int out=n;
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	int it=n/2;
	rep(i,n/2){
		while(a[it]<a[i]*2 && it<n) it++;
		if(it<n){
			out--;it++;
		}
	}
	cout<<out<<endl;
}