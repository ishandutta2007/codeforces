#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
ll gcd(ll r,ll v){
	if(v==0)return r;
	return gcd(v,r%v);
}
ll a,n,k,x[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>k;
	rep(i,1,a)cin>>x[i];
	while(1){
		n++;
		k-=n;
		if(k<1){
			k+=n;
			break;
		}
	}
	cout<<x[k]<<endl;
}