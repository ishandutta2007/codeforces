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
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,x[MAX],le,ri;
bool st;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n){
    	if(i!=x[i] && !st){
    		st = 1; le = i;
    		break;
		}
	}
	rap(i,n,1){
		if(i!=x[i]){
			ri = i; break;
		}
	}
	if(!st)return cout<<"0 0",0;
	if(ri==0)ri = n;
	reverse(x+le,x+ri+1);
	//cout<<le<<" "<<ri<<endl;
	rep(i,1,n)if(i!=x[i])return cout<<"0 0",0;
	cout<<le<<" "<<ri<<endl;
    return 0;
}