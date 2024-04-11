#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long 
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define MAX ((ll)(1e15+100))
#define ARRS ((ll)(1e6+100))
#define MOD ((ll)(1e9+7))
#define EP ((double)(1e-9))
#define EPS ((double)(1e-8))
#define pb push_back
#define PI ((double)3.141592653)


ll n,m,k,p;
ll a[ARRS];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	a[n]=MAX;
	n++;
	double pas=-1;
	for(int i=0; i<n; i++){
		ll k=upper_bound(a,a+n,a[i]+m)-a-1;
		if(k>=i+2)
			pas=max(pas,1.0*(0.0+a[k]-a[i+1])/(0.0+a[k]-a[i]));


	}
	if(pas<0)
		cout<<-1;
	else
		printf("%.10f",pas);
}