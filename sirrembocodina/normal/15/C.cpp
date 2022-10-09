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
#define pt pair<int,int>
#define otr pair<pt,pt>

//vector<int> a;

int64 f(int64 a){
	if(a==(int64)(0))
		return 0;
	if(a%4==0)
		return a;
	if(a%4==1)
		return (int64)(1);
	if(a%4==2)
		return a+1;
	return (int64)(0);
}

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n,ans;
	cin>>n;
	forn(i,n){
		int64 x,y;
		cin>>x>>y;
		if(!i)
			ans=f(x+y-1)^f(x-1);
		else
			ans=ans^f(x+y-1)^f(x-1);
	}
	if(ans)
		cout<<"tolik";
	else
		cout<<"bolik";
}