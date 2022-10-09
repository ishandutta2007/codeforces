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
	int n,x,l=0,r=1000,l1,r1;
	cin>>n>>x;
	forn(i,n){
		cin>>l1>>r1;
		if(r1<l1)
			swap(l1,r1);
		l=max(l,l1);
		r=min(r,r1);
	}
	if(r<l)
		cout<<-1;
	else{
		if((l<=x)&&(x<=r))
			cout<<0;
		else
			cout<<min(abs(x-l),abs(x-r));
	}
}