#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)

int t[200000],s[200000];

int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"1 0";
		return 0;
	}
	s[0]=0;
	forn(i,n){
		cin>>t[i];
		s[i+1]=s[i]+t[i];
	}
	int l=0,r=n-1;
	while(l!=r){
		int m=(l+r)/2;
		if(s[m]>s[n]-s[m+1])
			r=m;
		else
			l=m+1;
	}
	cout<<l<<' '<<n-l;
	return 0;
}