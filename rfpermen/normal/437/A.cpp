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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,k,a,b,c,x,y,z,sz[4],T,res,cnt;
string s,t;
bool st;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,3){
    	cin>>s;
    	sz[i] = s.size()-2;
	}
	rep(i,0,3){
		st = 1;
		if(i==0){
			if(sz[0]*2<=sz[1])a=1;
			else if(sz[0]>=sz[1]*2)a=2;
			else continue;
		}
		else {
			if(sz[i]*2<=sz[0])a=1;
			else if(sz[i]>=sz[0]*2)a=2;
			else continue;
		}
		rep(j,0,3){
			if(i==j)continue;
			if(a==1){
				if(sz[i]*2>sz[j])st = 0;
			}
			else {
				if(sz[i]<sz[j]*2)st = 0;
			}
		}
		if(st)res = i, cnt++;
	}
	if(cnt!=1)cout<<'C';
	else cout<<(char)(res+'A');
    return 0;
}