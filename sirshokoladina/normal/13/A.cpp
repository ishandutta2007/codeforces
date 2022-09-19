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

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n;
	cin>>n;
	int s=0,m;
	FORN(i,2,n){
		m=n;
		while(m){
			s+=m%i;
			m/=i;
		}
	}
	int p=n-2;
	FORN(i,2,p+1)
		while(p%i==0 && s%i==0){
			p/=i;
			s/=i;
		}
	cout<<s<<'/'<<p;
	return 0;
}