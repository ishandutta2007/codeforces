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
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,k,a,b,c,x,y,z,sz,cnt,ans,ttl,nw,id;
ll dp[MAX][2];
string s,t;
vector<pair<char,int> > v;
char ls;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    ls = s[0];
    for(auto i:s){
    	if(i==ls)cnt++;
    	else v.pb({ls,min(2,cnt)}), cnt = 1, ls = i;
	}
	v.pb({ls,min(2,cnt)});
	sz = v.size()-1;
	rep(i,0,sz){
		if(v[i].se==1)cout<<v[i].fi;
		else {
			if(i==sz)cout<<v[i].fi<<v[i].fi;
			else if(v[i+1].se==2){
				cout<<v[i].fi<<v[i].fi;
				i++;
				cout<<v[i].fi;
			}
			else cout<<v[i].fi<<v[i].fi;
		}
	}
    return 0;
}