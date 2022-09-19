#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

int a[1000];

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n,l;
	cin>>n>>l;
	forn(i,n)
		cin>>a[i];
	int mx=0;
	for(int k=l; k<110; k++){
		int x=0;
		forn(i,n)
			x+=a[i]/k;
		mx=max(mx,k*x);
	}
	cout<<mx;
	return 0;
}