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

vector<int> a;

int main(){
	// freopen("input.txt","rt",stdin);
	// freopen("output.txt","wt",stdout);
	int n;
	cin>>n;
	a.resize(n);
	forn(i,n)
		cin>>a[i];
	sort(a.begin(),a.end());
	int mn=a[0],ans=0;
	forn(i,n)
		if(a[i]>mn){
			ans=a[i];
			break;
		}
	if(ans)
		cout<<ans;
	else
		cout<<"NO";
}