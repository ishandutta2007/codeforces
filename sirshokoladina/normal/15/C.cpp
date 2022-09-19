#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

long long a(long long n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n%2==0)
		return a(n-1)^n;
	if(n%4==1)
		return 1;
	return 0;
}

int main(){
	int n;
	cin>>n;
	long long ans=0;
	forn(i,n){
		long long x,m;
		cin>>x>>m;
		ans^=(a(x-1)^a(x+m-1));
	}
	if(ans==0)
			cout<<"bolik\n";
		else
			cout<<"tolik\n";
	return 0;
}