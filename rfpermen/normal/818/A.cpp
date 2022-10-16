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
ll n,k,x,y,z,times;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	times=k+1;
	z=n/2;
	x=z/times;
	y=x*k;
	cout<<x<<" "<<y<<" "<<n-x-y<<endl;
}