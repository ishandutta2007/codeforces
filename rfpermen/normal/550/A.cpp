#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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

int ab,ba,aba,sz;
string s;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    rep(i,1,sz)if(s[i-1]=='A'&&s[i]=='B')ab++;
    rep(i,1,sz)if(s[i]=='A'&&s[i-1]=='B')ba++;
    rep(i,1,sz)if((s[i-2]=='B'&&s[i-1]=='A'&&s[i]=='B') || (s[i-2]=='A'&&s[i-1]=='B'&&s[i]=='A'))aba++;
    if(!ab || !ba)cout<<"NO";
    else if(ab==1 && ba==1 && aba)cout<<"NO";
    else if(((ab==2 && ba==1)||(ba==2 && ab==1))&&aba==2)cout<<"NO";
    else cout<<"YES";
    return 0;
}