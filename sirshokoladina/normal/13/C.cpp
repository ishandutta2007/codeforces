#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef pair<int,int> pii;
typedef long long int64;
typedef long double real;

#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define forn(i,n) FORN(i,0,n)
#define ford(i,n) FORD(i,0,n)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define length(a) ((int)(a).size())
#define high(a) (length(a)-1)
#define last(a) a[high(a)]
#define all(a) a.begin(),a.end()
#define norm(a) {sort(all(a));a.erase(unique(all(a)),a.end());}

int64 a[10000];
int64 d[2][10000],mn[2][10000];

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n;
	cin>>n;
	vector<int64> b;
	forn(i,n){
		cin>>a[i];
		b.pb(a[i]);
	}
	sort(all(b));
	forn(i,n)
		d[0][i]=abs(a[0]-b[i]);
	mn[0][0]=d[0][0];
	FORN(i,1,n)
		mn[0][i]=min(mn[0][i-1],d[0][i]);
	FORN(i,1,n){
		forn(j,n)
			d[i&1][j]=mn[1-(i&1)][j]+abs(a[i]-b[j]);
		mn[i&1][0]=d[i&1][0];
		FORN(j,1,n)
			mn[i&1][j]=min(mn[i&1][j-1],d[i&1][j]);
	}
	cout<<mn[1-(n&1)][n-1];
	return 0;
}