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
ll mp[ARRS];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	ll m=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		m=max(m,a[i]+1);
		mp[i]=max(mp[i-1],a[i]+1);
	}
	ll pas=0;
	for(int i=n; i>=1; i--){
		pas+=m-a[i]-1;
		if(mp[i-1]<m)m--;
		//cout<<a[i]<<" "<<m<<" "<<pas<<endl;
	}
	cout<<pas;



}