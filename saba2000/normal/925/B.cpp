#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define lol long long
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define MAX ((lol)(1e17+100))
#define MX ((lol)(4e9+100))
#define ARRS ((lol)(1e6+100))
#define ARS ((lol)(1e3+100))
#define HS ((lol)(233))
#define MOD ((lol)(1e9+9))
#define EP ((double)(1e-9))
#define EPS ((double)(1e-8))
#define pb push_back
#define PI ((double)3.141592653)
#define LG 21

ll n,m;
pair<ll,ll> a[ARRS];
pair<ll,ll> ma[ARRS];
ll k,p,s;
vector<ll> v[ARRS];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>p;
	for(int i=0; i<n; i++){
		cin>>a[i].fr;
		a[i].sc=i+1;
	}
	sort(a,a+n);
	ma[n]={-MAX,n};
	for(int i=n-1; i>=0; i--){

		ll c=(k+a[i].fr-1)/a[i].fr;
		if(i+c<=n-1&&ma[i+c].fr>=p){
			cout<<"Yes"<<endl;
			cout<<c<<" "<<n-ma[i+c].sc<<endl;
			for(int j=i; j<i+c; j++)
				cout<<a[j].sc<<" ";
			cout<<endl;
			for(int j=ma[i+c].sc; j<n; j++)
				cout<<a[j].sc<<" ";
			cout<<endl;

			return 0;
		}
		ma[i]=ma[i+1];
		ma[i]=max(ma[i],{a[i].fr*(n-i),i});
	}
	swap(k,p);
	for(int i=n-1; i>=0; i--){

		ll c=(k+a[i].fr-1)/a[i].fr;
		if(i+c<=n-1&&ma[i+c].fr>=p){
			cout<<"Yes"<<endl;
			cout<<n-ma[i+c].sc<<" "<<c<<endl;
			for(int j=ma[i+c].sc; j<n; j++)
				cout<<a[j].sc<<" ";
			cout<<endl;
			for(int j=i; j<i+c; j++)
				cout<<a[j].sc<<" ";
			cout<<endl;
			return 0;
		}
		ma[i]=ma[i+1];
		ma[i]=max(ma[i],{a[i].fr*(n-i),i});
	}
	cout<<"No";


}