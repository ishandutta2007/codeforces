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

long long f(int i,int n){
	if(i)
		return n/9+(n%9>=i);
	return n/9;
}

int main(){
	int n;
	cin>>n;
	long long ans=0;
	forn(i,9)
		forn(j,9){
			int k=(i*j)%9;
			ans+=f(i,n)*f(j,n)*f(k,n);
		}
	forn(i,n)
		ans-=n/(i+1);
	cout<<ans;
	return 0;
}