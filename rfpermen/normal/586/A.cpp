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
bool x[105];
int stat,ans,n;
int main(){
	cin>>n;
	rep(i,1,n)cin>>x[i];
	rep(i,1,n){
		if(x[i])stat=1;
		if(!x[i] && !x[i+1])stat=0;
		ans+=stat;
	}
	cout<<ans<<endl;
}