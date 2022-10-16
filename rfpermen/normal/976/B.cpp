#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=200005;
const int MOD=1000000000 + 7;
ll n,m,k,x,y;

int main(){
	cout<<fixed<<setprecision(25);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;k++;
	if(k<=n)cout<<k<<" "<<1<<endl;
	else {
		k-=n;m--;
		y=n; y-=(k-1)/m;
		//cout<<k<<endl;
		if(((k-1)/m)&1)cout<<y<<" "<<m+1-(k+m-1)%m<<endl;
		else if(k%m==0)cout<<y<<" "<<1+m<<endl;
		else cout<<y<<" "<<1+k%m<<endl;
	}
	return 0;
}