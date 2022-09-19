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
#define x first
#define c second
#define s(i,j) (sum[j+1]-sum[i])

pair<long long,long long> a[10000];

long long ans[10000],sum[10000];

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n;
	cin>>n;
	forn(i,n)
		cin>>a[i].x>>a[i].c;
	sort(a,a+n);
	sum[0]=0;
	forn(i,n)
		sum[i+1]=sum[i]+a[i].x;
	ans[n]=0;
	ford(i,n){
		ans[i]=(long long)1000000000 * (long long)1000000000;
		for(int j=i+1; j<=n; j++)
			ans[i]=min(ans[i],ans[j]+a[i].c+s(i+1,j-1)-a[i].x*(j-i-1));
	}
	cout<<ans[0];
	return 0;
}