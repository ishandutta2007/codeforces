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
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=200005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int sz,a,b;
string s;
int main(){
    cout<<fixed<<setprecision(3);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz=s.size();
    if(sz&1)return cout<<-1,0;
    rep(i,0,sz-1){
    	if(s[i]=='U')a--;
    	if(s[i]=='D')a++;
    	if(s[i]=='L')b--;
    	if(s[i]=='R')b++;
	}
	cout<<(abs(a)+abs(b))/2;
    return 0;
}