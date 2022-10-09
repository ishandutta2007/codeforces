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

int main(){
	int n,m,ans=0;
	cin>>n>>m;
	forn(i,m){
		int x,y;
		cin>>y>>x;
		a.pb(mp(x,y));
	}
	sort(a.begin(),a.end());
	forn(i,m/2)
		swap(a[i],a[m-i-1]);
	int i=0;
	while((n>0)and(i<m)){
		if(n>=a[i].sc){
			n-=a[i].sc;
			ans+=a[i].fs*a[i].sc;
		}
		else{
			ans+=a[i].fs*n;
			n=0;
		}
		i++;
	}
	cout<<ans;
}