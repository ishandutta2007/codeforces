#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=1e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};
ll n,le,ri,x[2*MAX],cnt,ls;
vector<pair<ll,bool> > v;

int main(){
    cout<<fixed<<setprecision(2);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>le>>ri, v.pb(mp(le,0)), v.pb(mp(ri+1,1));
    sort(v.begin(),v.end());
    ls=-1;
    for(auto i:v){
    	//cout<<i.se<<" "<<i.fi<<endl;
    	if(i.se){
			x[cnt]+=i.fi-ls;
    		cnt--;
    		ls=i.fi;
		}
		else {
			x[cnt]+=i.fi-ls;
			cnt++;
			ls=i.fi;
		}
		//cout<<ls<<" - "<<cnt<<endl;
	}
	rep(i,1,n)cout<<x[i]<<" "; cout<<endl;
    return 0;
}