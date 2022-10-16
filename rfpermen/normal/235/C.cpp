#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
struct state{
	int len,link,cnt;
	int nx[26];
}st[MAX<<1];

int id,last,cur,clone;
vector<int> v[MAX];

inline void sa_init(){
	st[0].link = -1;
	mems(st[0].nx,0);
	id = last = st[0].cnt = 0;
	return;
}

inline void sa_extend(int c){
	st[last].nx[c] = cur = ++id;
	st[cur].len = st[last].len + 1;
	v[st[cur].len].pb(cur);
	st[cur].cnt = 1;
	int p = last;
	while(1){
		p = st[p].link;
		if(p==-1){
			st[cur].link = 0;
			break;
		}
		if(st[p].nx[c]){
			int q = st[p].nx[c];
			if(st[p].len+1==st[q].len)st[cur].link = q;
			else {
				clone = ++id;
				st[clone] = st[q];
				st[clone].cnt = 0;
				st[clone].len = st[p].len+1;
				v[st[clone].len].pb(clone);
				st[q].link = st[cur].link = clone;
				while(p!=-1 && st[p].nx[c]==q){
					st[p].nx[c] = clone;
					p = st[p].link;
				}
			}
			break;
		}
		else st[p].nx[c] = cur;
	}
	/*
	online tapi TLE :p
	p = st[cur].link;
	while(p!=-1)++st[p].cnt, p = st[p].link;
	terus pas bikin clone biarin aja cnt[clone] = cnt[q] (gak ush dibikin jadi 0)
	*/
	last = cur;
	return;
}

int q,len,ans,tgt;
string s,t;
vector<int> del;
bool vis[MAX<<1];

inline int numCyclicalIsomorphic(){
	tgt = t.size();
	t+=t, cur = ans = len = 0;
	for(char c:t){
		c-='a';
		while(cur && !st[cur].nx[c])cur = st[cur].link, len = st[cur].len;
		
		if(st[cur].nx[c])++len, cur = st[cur].nx[c];
		if(len>=tgt){
			while(st[st[cur].link].len>=tgt)cur = st[cur].link, len = st[cur].len;
			if(vis[cur])break;
			vis[cur] = 1;
			del.pb(cur);
			ans+= st[cur].cnt;
		}
	}
	for(int i:del)vis[i] = 0;
	del.clear();
	return ans;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sa_init();
    cin>>s;
    for(char c:s)sa_extend(c-'a');
    rap(i,s.size(),1)for(int j:v[i])st[st[j].link].cnt+= st[j].cnt;
    cin>>q;
    while(q--){
    	cin>>t;
    	cout<<numCyclicalIsomorphic()<<endl;
	}
	return 0;
}