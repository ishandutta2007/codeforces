#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int a,b,n,m,x,y;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>a>>b>>x>>y;
    if((a+x<=n&&max(b,y)<=m)||(a+x<=m&&max(b,y)<=n))cout<<"YES";
    else if((b+y<=n&&max(a,x)<=m)||(b+y<=m&&max(a,x)<=n))cout<<"YES";
    else if(swap(a,b), (a+x<=n&&max(b,y)<=m)||(a+x<=m&&max(b,y)<=n))cout<<"YES";
    else if((b+y<=n&&max(a,x)<=m)||(b+y<=m&&max(a,x)<=n))cout<<"YES";
    else cout<<"NO";
    
    return 0;
}