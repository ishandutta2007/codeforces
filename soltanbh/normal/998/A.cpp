#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,a[13],mn=1e9,mx=0,j;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];maxm(mx,a[i]);minm(mn,a[i]);
	}
	f(i,0,n){
		if(a[i]==mn)
			j=i+1;
	}
	if(n>2 || mn!=mx){
		cout<<1<<endl<<j;
	}
	else cout<<-1;
}