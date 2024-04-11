#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,r[MAX],c[MAX],a,b;
char x;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n){
    	cin>>x;
    	if(x=='.'){
    		if(!r[i])r[i] = j, a++;
    		if(!c[j])c[j] = i, b++;
		}
	}
	if(a==n){
		rep(i,1,n)cout<<i<<" "<<r[i]<<endl;
		return 0;
	}
	if(b==n){
		rep(i,1,n)cout<<c[i]<<" "<<i<<endl;
		return 0;
	}
	cout<<-1;
    return 0;
}