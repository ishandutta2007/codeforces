#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+10;
ll ch[maxn],num[maxn];
int main(){
	ll n,m,dx,dy;cin>>n>>m>>dx>>dy;
	ll i=dx,j=dy;
	ch[0]=0;
	while(!(i==0&&j==0)){
		ch[i]=j;
		i=(i+dx)%n;
		j=(j+dy)%n;
	}
	for(ll i=0;i<m;i++){
		ll a,b;cin>>a>>b;
		num[((b-ch[a])+n)%n]++;
	}
	ll Max=0,Maxi;
	for(ll i=0;i<n;i++){
		if(num[i]>Max){
			Max=num[i];
			Maxi=i;
		}
	}
	cout<<0<<" "<<Maxi;
}