#include <bits/stdc++.h>
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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
#define piiii pair<piii,pii>
#define pdd pair<double,double>
//#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,x,y;
vector<pii> ans,ans2;
string s;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    x = y = 1;
    rep(i,2,n){
    	if(x!=n){
			cout<<"? "<<x+1<<" "<<y<<" "<<n<<" "<<n<<endl;
    		cin>>s;
    		if(s=="YES"){
    			x++;
    			ans.pb({x,y});
    			continue;
			}
		}
    	y++;
    	ans.pb({x,y});
	}
	x = y = n;
	ans2.pb({n,n});
	rep(i,3,n){
		if(y!=1){
			cout<<"? 1 1 "<<x<<" "<<y-1<<endl;
    		cin>>s;
    		if(s=="YES"){
    			y--;
    			ans2.pb({x,y});
    			continue;
			}
		}
    	x--;
    	ans2.pb({x,y});
	}
	cout<<"! ";
	x = y = 1;
	for(auto i:ans){
		if(i.fi>x)cout<<'D', x++;
		else cout<<'R', y++;
	}
	reverse(ans2.begin(),ans2.end());
	for(auto i:ans2){
		if(i.fi>x)cout<<'D', x++;
		else cout<<'R', y++;
	}
	cout<<endl;
    return 0;
}