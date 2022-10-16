#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll s,k,x[1000],cnt;
vector<int> ans;

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>k;
    if(k>29){
    	cout<<__builtin_popcountll(s)+1<<endl;
    	rep(i,0,29)if(s&(1<<i))cout<<(1<<i)<<" "; cout<<"0";
    	return 0;
	}
	x[k] = 1;
	rep(i,k+1,1000){
		rep(j,i-k,i-1)x[i]+=x[j];
		if(x[i]>s)break;
		cnt++;
	}
	rap(i,k+cnt,k){
		if(s>=x[i])ans.pb(x[i]), s-=x[i];
	}
	ans.pb(0);
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
    return 0;
}