//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define mkp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define pb push_back
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 2e6 + 9;
const int L = 20;
const int base = 37;
const int Mod = 1e9 + 7;
int match[N],sa[N],l[N],r[N];
string s[N];
vector<ll> h[N];
set<pair<int,pii> > q;
int get_lcp(int x,int y) {
	int cur = 0;
	for(int b = L - 1; ~b; --b) {
		cur += 1 << b;
		if(cur <= min(s[x].size(),s[y].size()) && h[x][cur - 1] == h[y][cur - 1]);
		else cur -= 1 << b;
	}
	return cur;
}
bool cmp(int x,int y) {
	int lcp = get_lcp(x,y);
	if(s[x].size() == s[y].size() && s[x].size() == lcp) return 0;
	if(s[x].size() == lcp) return 1;
	if(s[y].size() == lcp) return 0;
	return s[x][lcp] < s[y][lcp]; 
}
int main(){
	memset(match,-1,sizeof match);
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	For(i,0,n) cin >> s[i];
	For(i,0,n) cin >> s[i + n];
	For(i,0,2 * n) {
		ll lst = 0;
		For(j,0,s[i].size()) {
			h[i].push_back(((lst * base) + s[i][j]) % Mod);
			lst = (lst * base) + s[i][j];
			lst %= Mod;
		}
	}
	For(i,0,2 * n) sa[i] = i;
	sort(sa,sa+n * 2,cmp);
	For(i,0,n * 2) l[i] = i - 1,r[i] = i + 1;
	r[n * 2 - 1] = -1;
	int res = 0;
	For(i,0,n * 2) {
		int nx = r[i];
		if(nx == -1) continue;
		if((sa[i] / n) + (sa[nx] / n) == 1) {
			q.insert({-get_lcp(sa[i],sa[nx]),{i,nx}});
		}
	}
	while(q.size()) {
		pair<int,pii> cur = *(q.begin());
		q.erase(cur);
		int id1 = cur.S.F,id2 = cur.S.S;
		if(match[sa[id1]] + 1 || match[sa[id2]] + 1) continue;
		res += get_lcp(sa[id1],sa[id2]);
		match[sa[id1]] = sa[id2];
		match[sa[id2]] = sa[id1];
		int pre = l[id1];
		int nex = r[id2];
		if(pre + 1) r[pre] = nex;
		if(nex + 1) l[nex] = pre;
		if(pre == -1 || nex == -1) continue;
		if((sa[pre] / n) + (sa[nex] / n) != 1) continue;
		q.insert({-get_lcp(sa[pre],sa[nex]),{pre,nex}});
	}
	cout << res << '\n';
	For(i,0,n) {
		cout << i + 1 << ' ' << match[i] - n + 1 << '\n';
	}
	return 0;
}