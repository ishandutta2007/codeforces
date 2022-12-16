// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=510,mod=1e9+7;
const ll inf=1e18;

string s[maxn];
int a[maxn][maxn], b[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;

    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
	    if(j<m && s[i-1][j-1]=='.' && s[i-1][j]=='.') a[i][j]=1;
	    if(i<n && s[i-1][j-1]=='.' && s[i][j-1]=='.') b[i][j]=1;
	    a[i][j]+= a[i][j-1];
	    b[i][j]+= b[i-1][j];
	}
    }
    int q; cin>>q;
    while(q--){
	int x,y,xx,yy,ans=0; cin>>x>>y>>xx>>yy;

	for(int i=x;i<=xx;i++)
	    ans+= a[i][yy-1] - a[i][y-1];
	for(int j=y;j<=yy;j++)
	    ans+= b[xx-1][j] - b[x-1][j];
	cout<<ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")