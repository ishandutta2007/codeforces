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
ll n,a[100005],b[100005];
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rap(i,n,1){
		b[i]=a[i]+a[i+1];
	}
	rep(i,1,n){
		cout<<b[i];
		if(i<n)cout<<" ";
		else cout<<endl;
	}
}