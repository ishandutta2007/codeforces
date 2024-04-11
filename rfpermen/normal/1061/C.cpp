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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

int n,m,a,b,x[MAX],y,z,sz,cnt,res,tmp;
ll ans[MAX];
string s,t;
char c;

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    ans[1] = 1;
    rep(i,2,n){
    	tmp = sqrt(x[i]);
    	rap(j,tmp,1){
    		if(x[i]%j)continue;
			y = x[i]/j;
    		if(y<=i&&y!=j)ans[y] = (ans[y-1]+ans[y])%MOD;
    		ans[j] = (ans[j-1]+ans[j])%MOD;
		}
		ans[1]++;
	}
//	rep(i,1,n)cout<<ans[i]<<endl;
	rep(i,1,n)z = (z+ans[i])%MOD;
	cout<<z;
    return 0;
}