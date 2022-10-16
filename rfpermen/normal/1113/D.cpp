#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int MAX = 1<<20;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n;
string s;
char ls;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    if(s.size()==1)return cout<<"Impossible",0;
    n = s.size()/2-1;
    st = s.size()&1;
    ls = s[0];
    rep(i,0,n){
    	if(s[i]!=ls)break;
    	if(i==n)return cout<<"Impossible",0;
	}
	rep(i,0,n/2)if(s[i]!=s[n-i])return cout<<1+st,0;
	if(n&1){
		if(st)cout<<2;
		else {
			while(1){
				n = (n-1)/2;
				rep(i,0,n/2)if(s[i]!=s[n-i])return cout<<1,0;
				if(n%2==0)return cout<<2,0;
			}
		}
	}
	else cout<<2;
	return 0;
}