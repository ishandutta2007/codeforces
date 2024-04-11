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

int nod(int a,int b){
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	return nod(b,a%b);
}

int main(){
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	int k=nod(x,y);
	x/=k;
	y/=k;
	int a1=a/x,b1=b/y;
	cout<<min(a1,b1)*x<<" "<<min(a1,b1)*y;
}