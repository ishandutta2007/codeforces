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
const int MAX=100005;
const int MOD=1000000000 + 7;
ll n,x[222000],mx,pos;

int main(){
	//cout<<fixed<<setprecision(25);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>pos;
	rep(i,1,n)cin>>x[i];
	sort(x+1,x+1+n);
	if(x[pos]==x[pos+1] || (pos==0 && x[1]==1))cout<<-1<<endl;
	else if(pos==0)cout<<x[1]-1<<endl;
	else cout<<x[pos]<<endl;
	return 0;
}