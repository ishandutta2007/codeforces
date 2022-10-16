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
ll a,b,c,d,e,ans;
bool drag[100005];
int main(){
	cin>>a>>b>>c>>d>>e;
	for(int i=a;i<=e;i+=a)drag[i]=1;
	for(int i=b;i<=e;i+=b)drag[i]=1;
	for(int i=c;i<=e;i+=c)drag[i]=1;
	for(int i=d;i<=e;i+=d)drag[i]=1;
	rep(i,1,e)if(drag[i])ans++;
	cout<<ans<<endl;
}