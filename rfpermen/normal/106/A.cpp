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
//#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c,x,y,z,sz,cnt,tmp,ans,le,ri;
string s,t;
char rem;
map<char,int> m;
int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    m['6'] = 1;
    m['7'] = 2;
    m['8'] = 3;
    m['9'] = 4;
    m['T'] = 5;
    m['J'] = 6;
    m['Q'] = 7;
    m['K'] = 8;
    m['A'] = 9;
    cin>>rem>>s>>t;
    x = m[s[0]];
    y = m[t[0]];
    if(s[1]==t[1]){
    	if(x>y)cout<<"YES";
    	else cout<<"NO";
	}
	else if(s[1]==rem)cout<<"YES";
	else cout<<"NO";
    return 0;
}