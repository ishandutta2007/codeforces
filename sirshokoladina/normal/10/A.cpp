#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define last(a) a[a.size()-1]

int l[1000],r[1000];

int main(){
	int n,p1,p2,p3,t1,t2;
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	forn(i,n)
		cin>>l[i]>>r[i];
	int s=(r[n-1]-l[n-1])*p1;
	forn(i,n-1){
		s+=(r[i]-l[i])*p1;
		s+=min(l[i+1]-r[i],t1)*p1;
		s+=max(0,min(l[i+1]-r[i]-t1,t2))*p2;
		s+=max(0,l[i+1]-r[i]-t1-t2)*p3;
	}
	cout<<s;
	return 0;
}