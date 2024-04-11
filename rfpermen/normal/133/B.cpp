#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000 + 3;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

string s;
int b[405],cnt=-1,ans,x,c[128];
bool vis[405];

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    c['>'] = 8;
    c['<'] = 9;
    c['+'] = 10;
    c['-'] = 11;
    c['.'] = 12;
    c[','] = 13;
    c['['] = 14;
    c[']'] = 15;
    b[0] = 1;
    rep(i,1,400)b[i] = (b[i-1]*2)%MOD;
    cin>>s;
    for(auto i:s){
    	x = c[i];
    	//cout<<x<<endl;
    	rap(j,3,0){
    		cnt++;
    		if(x&(1<<j))vis[cnt] = 1;
		}
	}
	//rep(i,0,cnt)cout<<vis[i]; cout<<endl;
	reverse(vis,vis+cnt+1);
	rep(i,0,cnt)if(vis[i])ans+=b[i];
	cout<<ans%MOD<<endl;
    return 0;
}