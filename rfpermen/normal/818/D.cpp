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
ll n,k,x[1000005],y[100005],tmp,ans;
bool z[1000005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	rep(i,1,n)cin>>y[i];
	memset(z,1,sizeof z);
	rep(i,1,n){
		if(y[i]==k)x[k]++;
		else if(x[y[i]]<x[k])z[y[i]]=0;
		else x[y[i]]++;
	}
	rep(i,1,1000000){
		if(i==k)continue;
		if(x[i]>=x[k] && z[i]){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}