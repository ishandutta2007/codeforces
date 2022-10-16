#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int sz,pos;
string s,x,y,ans;
 
string cmp(string a,string b){
	if(a.size()>b.size())return b;
	if(a.size()<b.size())return a;
	int siz = a.size()-1;
	rep(i,0,siz){
		if(a[i]<b[i])return a;
		else if(a[i]>b[i])return b;
	}
	return a;
}
 
string solve(string a,string b){
	string ret = "";
	reverse(all(a));
	reverse(all(b));
	if(a.size()<b.size())swap(a,b);
	int sa = a.size()-1, sb = b.size()-1;
//	exit(0);
	rep(i,0,sa){
		if(i<=sb)a[i]+=b[i]-'0';
		if(a[i]>'9'){
			a[i]-='0';
			if(i==sa)a.pb('0'+a[i]/10), sa++;
			else a[i+1]+=a[i]/10;
			a[i]%=10;
			a[i]+='0';
		}
	}
	reverse(all(a));
	return a;
}
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>s;
    ans = s;
    sz = s.size()-1;
    rap(i,sz/2,1){
    	if(s[i]!='0'){
    		x = y = "";
    		rep(j,0,i-1)x.pb(s[j]);
    		rep(j,i,sz)y.pb(s[j]);
    		ans = cmp(ans,solve(x,y));
    		break;
		}
	}
	rep(i,sz/2+1,sz){
		if(s[i]!='0'){
    		x = y = "";
    		rep(j,0,i-1)x.pb(s[j]);
    		rep(j,i,sz)y.pb(s[j]);
    		ans = cmp(ans,solve(x,y));
    		break;
		}
	}
	cout<<ans<<endl;
	return 0;
}