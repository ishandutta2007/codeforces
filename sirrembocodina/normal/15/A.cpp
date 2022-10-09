#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=n-1;i>=0;i--)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pi 3.1415926535897932

vector<pair<int,int> > a;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.fs<b.fs;
}

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);                                                                                                                                                                                       
	int n,t;
	cin>>n>>t;
	if(n==0){
		cout<<0;
		return 0;
	}
	forn(i,n){
		int x,y;
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	int ans=2;
	sort(a.begin(),a.end(),cmp);
	forab(i,1,n)
		if(2*a[i].fs-a[i].sc-2*t>2*a[i-1].fs+a[i-1].sc)
			ans++;
//	cout<<ans<<endl;
	forn(i,n-1)
		if(2*a[i].fs+a[i].sc+2*t<2*a[i+1].fs-a[i+1].sc)
			ans++;
//	cout<<ans<<endl;
	forn(i,n-1)
		if(2*a[i].fs+a[i].sc+2*t==2*a[i+1].fs-a[i+1].sc)
			ans++;
	cout<<ans;
}