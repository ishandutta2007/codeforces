#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int sz;
char c;
string s[]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"},t;
map<char,char> m;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sz = 8;
    cin>>c>>t;
    if(c=='R'){
    	rep(i,0,2)rep(j,0,8)m[s[i][j+1]]=s[i][j];
    	for(auto i:t)cout<<m[i];
	}
	else {
    	rep(i,0,2)rep(j,0,8)m[s[i][j]]=s[i][j+1];
    	for(auto i:t)cout<<m[i];
	}
    return 0;
}