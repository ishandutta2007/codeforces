#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<N;i++)
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 3e5+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,x[3],m;
string s;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for(auto i:s)x[i-'0']++;
    m = n/3;
    rep(i,0,n){
    	if(x[0]>=m)break;
    	if(x[s[i]-'0']>m)x[s[i]-'0']--, x[0]++, s[i] = '0';
	}
	rep(i,0,n){
		if(x[1]>=m)break;
		if(s[i]=='2'&&x[2]>m)x[2]--, x[1]++, s[i] = '1';
	}
	rap(i,n-1,0){
		if(x[2]>=m)break;
    	if(x[s[i]-'0']>m)x[s[i]-'0']--, x[2]++, s[i] = '2';
	}
	rap(i,n-1,0){
		if(x[1]>=m)break;
		if(s[i]=='0'&&x[0]>m)x[0]--, x[1]++, s[i] = '1';
	}
//	rep(i,0,3)cout<<x[i]; cout<<endl;
	cout<<s;
    return 0;
}