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

int n,tmp,cnt;
vector<int> ans,v;

void built(){
	do{
		if(v[0]==0)continue;
		tmp = 0;
		for(auto i:v)tmp = tmp*10 + i;
		ans.pb(tmp);
	}while(next_permutation(v.begin(),v.end()));
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,9){
    	tmp = 0;
    	rep(j,1,9){
    		tmp = tmp*10 + i;
    		ans.pb(tmp);
		}
	}
	rep(i,0,8)rep(j,i+1,9){
		rep(k,2,9){
			rep(o,1,k-1){
				v.clear();
				rep(x,1,o)v.pb(i);
				rep(x,o+1,k)v.pb(j);
				built();
			}
		}
	}
	ans.pb(1000000000);
	sort(ans.begin(),ans.end());
	//cout<<ans.size()<<endl;
	//rep(i,0,1000)cout<<ans[i]<<endl;
    cin>>n;
    for(auto i:ans){
    	if(i>n)break;
    	cnt++;
	}
	cout<<cnt<<endl;
    return 0;
}