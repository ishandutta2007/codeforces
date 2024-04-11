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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=5e4+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,y,z[MAX],a,b,ans,ls,x[MAX];
bool st;

int main(){
	//cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>y>>n;
    rep(i,1,n)cin>>a, x[a]++;
    sort(x+1,x+1+100);
    reverse(x+1,x+1+100);
    rep(i,1,20000){
    	rep(j,1,100)z[j] = x[j];
    	a = 1;
    	st = 1;
    	//rep(j,1,100)cout<<z[j]<<" "; cout<<endl;
    	rep(j,1,y){
    		if(!st)break;
    		//cout<<z[a]<<" "<<i<<endl;
    		if(z[a]<i){
    			a++;
    			if(z[a]<i)st = 0;
    			else z[a]-=i;
			}
			else z[a]-=i;
		}
		if(!st)break;
		ans = i;
	}
	cout<<ans<<endl;
    return 0;
}