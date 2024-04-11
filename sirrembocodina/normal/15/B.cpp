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

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int64 n,m,x1,x2,y1,y2,t;
	cin>>t;
	forn(i,t){
		cin>>n>>m>>x1>>y1>>x2>>y2;
		int64 x=abs(x1-x2),y=abs(y1-y2);
		int64 ans;
		ans=2*(n-x)*(m-y);
		ans-=max((int64)(0),n-2*x)*max((int64)(0),m-2*y);
		cout<<n*m-ans<<endl;
	}
}