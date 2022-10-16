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
#define pic pair<int,char> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=31623000;
const ll MAX2 = 1951975;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
pic n[3];
char a,b,c,ans[]={'A','B','C'};
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,2){
    	n[i].se='A'+i;
    	cin>>a>>b>>c;
    	if(b=='>')n[a-'A'].fi++;
    	else n[c-'A'].fi++;
	}
	sort(n,n+3);
	rep(i,0,2){
		if(n[i].fi!=i)return cout<<"Impossible" , 0;
	}
	rep(i,0,2)cout<<n[i].se;
    return 0;
}