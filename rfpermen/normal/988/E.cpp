#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll sz,x,ans,nw;
string s,t;

void cek(){
	rep(i,0,sz){
		if(t[i]!='0'){
			rap(j,i,1)swap(t[i],t[i-1]),++nw;
			break;
		}
	}
	x = 0;
	for(auto i:t)x = x*10 + i-'0';
	if(x%25==0)ans = min(ans,nw);
}

void solve(char b,char a){
	t = s, nw = 0;
    if(t[sz]!=a){
    	rap(i,sz-1,0)if(t[i]==a){
    		rep(j,i,sz-1)swap(t[j],t[j+1]), ++nw;
    		break;
		}
	}
    if(t[sz-1]!=b){
    	rap(i,sz-2,0)if(t[i]==b){
    		rep(j,i,sz-2)swap(t[j],t[j+1]), ++nw;
    		break;
		}
	}
	cek();
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s; sz = s.size()-1;
    if(sz==0)return cout<<"-1\n",0;
    ans = MAX;
    solve('0','0');
    solve('2','5');
    solve('5','0');
    solve('7','5');
    cout<<(ans!=MAX ? ans : -1)<<endl;
    return 0;
}