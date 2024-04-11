#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,N) for(int i = n; i<=N; i++)
#define ll long long

ll n,k,x[200005],ans,nw,df,cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	rep(i,1,n){
		cin>>x[i];
		df = min(k-x[i-1],x[i]);
		if(x[i-1])x[i]-=df, cnt++;
		cnt+=x[i]/k;
		x[i]%=k;
	}
	if(x[n])cnt++;
	cout<<cnt<<endl;
	return 0;
}