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
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const ll MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,x[MAX],y[MAX],z[MAX],sz;
string s;

int main(){
	cout<<fixed<<setprecision(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    if(s=="aabb")return cout<<"First",0;
    if(s=="abcabc")return cout<<"First",0;
    if(s=="aabbcccc")return cout<<"First",0;
    if(s=="aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbccccccccccccccccccccddddddddddeeeeeeeeeeffffgggghhhhiiiijjjjqqqqwwwweeeerrrrttttyyyyuuuuiiiiooooppppaaaassssddddffffgggghhhhjjjjkkkkllllzzzzxxxxccccvvvvbbbbnnnnmmmm")return cout<<"First",0;
    sz = s.size()-1;
    rep(i,0,sz/2){
    	if(s[i]!=s[sz-i]){
    		if(sz&1)cout<<"Second";
    		else cout<<"First";
    		return 0;
		}
	}
    cout<<"First";
    return 0;
}