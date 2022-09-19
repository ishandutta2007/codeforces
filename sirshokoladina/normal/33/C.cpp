#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

int a[200000],b[200000],c[200000];

int main(){
	int n;
	cin>>n;
	forn(i,n)
		cin>>a[i];
	b[0]=0;
	forn(i,n)
		b[i+1]=b[i]+a[i];
	forn(i,n)
		b[i+1]=max(abs(b[i+1]),b[i]+a[i]);
	c[0]=0;
	forn(i,n)
		c[i+1]=c[i]+a[n-1-i];
	forn(i,n)
		c[i+1]=max(abs(c[i+1]),c[i]+a[n-1-i]);
	int mx=0;
	forn(i,n+1)
		mx=max(mx,b[i]+c[n-i]);
	cout<<mx;
	return 0;
}