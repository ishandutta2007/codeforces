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

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	long long n,m,x,y;
	cin>>n>>x>>m>>y;
	long long d=abs(x-y);
	long long v=0;
	long long k=1;
	for(int i=1;i<=m;i++){
		long long x=abs(d-i);
		long long y=d+i;
		if(x>n){
			k++;
			continue;
		}
		if(x==0)
			v+=2*n;
		else
			v+=2*n-2*x+1;
		if(y<=n)
			v-=1+2*n-2*y;
	}
	for(int i=1;i<=n;i++){
		long long x=abs(d-i);
		if(x>m)
			k++;
	}
	if(v)
		cout<<v+k+1;
	else
		cout<<k;
	return 0;
}