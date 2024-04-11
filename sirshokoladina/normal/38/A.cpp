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
	int n;
	cin>>n;
	forn(i,n-1)
		cin>>a[i];
	int c,b;
	cin>>c>>b;
	int s=0;
	for(int i=c-1; i<b-1; i++)
		s+=a[i];
	cout<<s;
	return 0;
}