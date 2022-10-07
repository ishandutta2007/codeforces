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
vector<ll> v[ARRS];
string s;



double dst(pair<ll,ll> x,pair<ll,ll> y){
	return sqrt((x.fr-y.fr)*(x.fr-y.fr)+(x.sc-y.sc)*(x.sc-y.sc));
}

double dest(pair<ll,ll> k,pair<ll,ll> p,pair<ll,ll> t){
	double a=dst(k,p);
	double b=dst(k,t);
	double c=dst(p,t);
	
	double pr=(a+b+c)/2.0;
	double s=sqrt(pr*(pr-a)*(pr-b)*(pr-c));
	double h=2.0*s/c;
	return h;
}


pair<ll,ll> x[ARRS];


int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i].fr>>x[i].sc;
	}
	double pas=MAX;
	for(int i=0; i<n; i++){
		auto a=x[i];
		auto b=x[(i+1)%n];
		auto c=x[(i+2)%n];
		//cout<<dest(b,a,c)<<endl;
		pas=min(pas,dest(b,a,c)/2.0);
	}
	printf("%.9f",pas);



}