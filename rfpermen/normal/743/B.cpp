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
ll n,t,ans;
int main(){
	cin>>n>>t;
	ans=1;
	while(t%2==0){
		ans++;
		t/=2;
	}
	cout<<ans<<endl;
}