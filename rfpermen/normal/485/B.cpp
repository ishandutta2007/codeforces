#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define MAX 10005
using namespace std;
ll n,x,y,le,ri,up,don,ans;
int main(){
	le=1e10,ri=-1e10,up=-1e10,don=1e10;
	cin>>n;
	rep(i,1,n){
		cin>>x>>y;
		if(le>x)le=x;
		if(ri<x)ri=x;
		if(don>y)don=y;
		if(up<y)up=y;
	}
	ans=max(ri-le,up-don);
	cout<<ans*ans<<endl;
}