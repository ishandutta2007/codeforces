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

bool line(vector<int64> a,vector<int64> b,vector<int64> c){
	return ((a[0]-b[0])*(b[1]-c[1])==(a[1]-b[1])*(b[0]-c[0]));
}

int64 len(vector<int64> a,vector<int64> b){
	return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int t;
	cin>>t;
	forn(tt,t){
		bool bad=0;
		vector<vector<vector<int64> > > a(3,vector<vector<int64> >
(2,vector<int64>(2)));
		forn(i,3){
			forn(j,2)
				forn(k,2)
					cin>>a[i][j][k];
			if(len(a[i][0],a[i][1])==0)
				bad=1;
		}
		forn(i1,3)
			forn(i2,2)
				forn(j1,i1)
					forn(j2,2)
						if(a[i1][i2]==a[j1][j2]){
							swap(a[0],a[j1]);
							swap(a[0][j2],a[0][0]);
							swap(a[1],a[i1]);
							swap(a[1][i2],a[1][0]);
							break;
						}
//		cout<<bad;
		if(a[0][0]!=a[1][0])
			bad=1;
//		cout<<bad;
		if(!line(a[0][0],a[0][1],a[2][0]))
			swap(a[2][0],a[2][1]);
//		cout<<bad;
		if(!line(a[0][0],a[0][1],a[2][0]))
			bad=1;
//		cout<<bad;
		if(!line(a[1][0],a[1][1],a[2][1]))
			bad=1;
//		cout<<bad;
		if(line(a[0][0],a[0][1],a[1][1]))
			bad=1;
//		cout<<bad;
		if(len(a[0][0],a[0][1])+len(a[1][0],a[1][1])<len(a[0][1],a[1][1]))
			bad=1;
//		cout<<bad;
		if(a[2][0]==a[0][1] || a[2][1]==a[1][1])
			bad=1;
		int64 x1=len(a[0][0],a[2][0]),x2=len(a[2][0],a[0][1]);
		int64 y1=len(a[1][0],a[2][1]),y2=len(a[2][1],a[1][1]);
		int64 x3=len(a[0][0],a[0][1]),y3=len(a[1][0],a[1][1]);
//		cout<<' '<<x<<' '<<y<<' ';
		if(25*y1<y3 || y1>y3 || 25*y2<y3 || y2>y3)
			bad=1;
		if(25*x1<x3 || x1>x3 || 25*x2<x3 || x2>x3)
			bad=1;
//		cout<<bad;
		if(bad)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}