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
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,sz,id;
bool ans[MAX],st;
string t;
pair<string,int> s[MAX];
char r[MAX];

bool cmp(pair<string,int> a,pair<string,int> b){
	if(a.fi.size()==b.fi.size())return a.se>b.se;
	return a.fi.size()>b.fi.size();
}

int main(){
//	cout<<fixed<<setprecision(1);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    n = n*2-2;
    rep(i,1,n){
    	cin>>s[i].fi;
    	s[i].se = i;
	}
	sort(s+1,s+1+n,cmp);
	t = s[1].fi, sz = t.size()-1;
	rep(i,0,sz)r[i] = t[i];
	rep(i,1,n){
		if(st)break;
//		cout<<s[i].fi<<"------ ";
//		rep(j,0,n/2)cout<<r[j]; cout<<endl;
		sz = s[i].fi.size()-1;
		if(i&1)rep(j,0,sz){
			if(s[i].fi[j]!=t[j]){
				id = n/2;
				rap(k,sz,0){
					if(r[id]==0)r[id] = s[i].fi[k];
					if(r[id]!=s[i].fi[k])st = 1;
					if(!k)ans[s[i].se] = 0;
					id--;
				}
				break;
			}
			if(j==sz)ans[s[i].se] = 1;
		}
		else {
			if(ans[s[i-1].se]){
				id = n/2;
				rap(k,sz,0){
					if(r[id]==0)r[id] = s[i].fi[k];
					if(r[id]!=s[i].fi[k])st = 1;
					if(!k)ans[s[i].se] = 0;
					id--;
				}
			}
			else {
				rep(j,0,sz){
					if(s[i].fi[j]!=t[j])st = 1;
					if(j==sz)ans[s[i].se] = 1;
				}
			}
		}
	}
	if(st){
		reverse(all(t));
		rep(i,1,n)reverse(all(s[i].fi));
		rep(i,0,sz)r[i] = t[i];
		rep(i,1,n){
			sz = s[i].fi.size()-1;
			if(i&1)rep(j,0,sz){
				if(s[i].fi[j]!=t[j]){
					ans[s[i].se] = 1;
					break;
				}
				if(j==sz)ans[s[i].se] = 0;
			}
			else ans[s[i].se] = ans[s[i-1].se]^1;
		}
	}
	rep(i,1,n)if(ans[i])cout<<'P'; else cout<<'S';
    return 0;
}