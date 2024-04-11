#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

long long gcd(long long n,long long m){
	if(m)
		return gcd(m,n%m);
	return n;
}

int main(){
        long long a,b,x,y;
	cin>>a>>b>>x>>y;
	long long d=gcd(x,y);
	x/=d;
	y/=d;
	int k=min(a/x,b/y);
	cout<<x*k<<' '<<y*k; 
	return 0;
}