#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int cnt[26],x,y,z,sz,ans;
string s,t;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    if(s.size()<t.size())return cout<<0,0;
    x = t.size();
    for(auto i:t)cnt[i-'0']++;
	sz = t.size()-2;
	rep(i,0,sz){
		if(s[i]!='?'){
			cnt[s[i]-'0']--;
			if(cnt[s[i]-'0']>=0)x--;
		}
		else y++;
	}
	sz = s.size()-1;
	rep(i,t.size()-1,sz){
		if(s[i]!='?'){
			cnt[s[i]-'0']--;
			if(cnt[s[i]-'0']>=0)x--;
		}
		else y++;
//		cout<<x<<' '<<y<<endl;
//		cout<<s[i-(int)t.size()+1]<<endl;
		if(x-y==0)ans++;
		if(s[i-(int)t.size()+1]!='?'){
			cnt[s[i-(int)t.size()+1]-'0']++;
			if(cnt[s[i-(int)t.size()+1]-'0']>0)x++;
		}
		else y--;
	}
	cout<<ans<<endl;
	return 0;
}