#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,pos,x;
string s,t;
bool st;

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size()-1;
    t = s[0];
    rep(i,2,n){
    	if(s[i]=='e'){
    		pos = i+1;
    		break;
		}
		t+= s[i];
	}
	rep(i,pos,n)x = x*10 + (s[i]-'0');
	while(!t.empty() && t.back()=='0')t.pob();
	if(t.empty())return cout<<"0\n",0;
	
	n = t.size()-1;
	if(x>=n){
		for(char c:t)if(st || c!='0')cout<<c, st = 1;
		rep(i,n+1,x)cout<<0;
	}
	else {
		rep(i,0,x)if(st || t[i]!='0')cout<<t[i], st = 1;
		if(!st)cout<<0;
		cout<<'.';
		rep(i,x+1,n)cout<<t[i];
	}
	cout<<endl;
	return 0;
}