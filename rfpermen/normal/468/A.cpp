#include <bits/stdc++.h>

#pragma GCC optimize("Os")
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
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,ans[MAX],y;
pii x[MAX];

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n<4)return cout<<"NO\n",0;
    cout<<"YES\n";
    if(n==4)cout<<"3 * 4 = 12\n12 * 2 = 24\n24 * 1 = 24\n";
    else if(n==5)cout<<"5 * 4 = 20\n20 + 3 = 23\n2 - 1 = 1\n23 + 1 = 24\n";
    else {
    	cout<<"3 - 2 = 1\n1 - 1 = 0\n5 * 0 = 0\n";
    	cout<<"4 * 6 = 24\n";
    	rep(i,7,n)cout<<i<<" * 0 = 0\n";
    	cout<<"24 + 0 = 24\n";
	}
    return 0;
}