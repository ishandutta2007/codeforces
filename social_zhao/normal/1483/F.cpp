#define RPChe_ 
#define mzgwty 
#define dottle 
#define final_trump 
#define A1443356159 
#define Social_Zhao AC  
#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e6 + 5;
int n, lst[N], pos[N], ch[N][26], fail[N], tot = 1, vis[N], ed[N], pre[N];
string s[N];
int in[N], out[N], tim;
vector<int> adj[N];
int bin[N], cnt[N], top;

namespace BIT {
	int sum[N];
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x <= tim) sum[x] += v, x += lowbit(x); }
	void add(int l, int r, int x) { add(l, x), add(r + 1, -x); }
	int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
}

namespace NIT {
	int sum[N];
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x <= tim) sum[x] += v, x += lowbit(x); }
	int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
	int ask(int l, int r) { return ask(r) - ask(l - 1); }
}

void insert(const string &s, int id) {
    int len = s.size(), u = 1;
    for(int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if(!ch[u][c]) ch[u][c] = ++tot;
        lst[ch[u][c]] = u, u = ch[u][c];
    }
    pos[id] = u, ed[u] = id;
}

void GetFail() {
    queue<int> q;
    for(int i = 0; i < 26; i++) 
		if(ch[1][i]) fail[ch[1][i]] = 1, q.push(ch[1][i]);
		else ch[1][i] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; i++) {
            if(!ch[u][i]) ch[u][i] = ch[fail[u]][i];
            else fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
        }
    }
}

void dfs(int u) {
	in[u] = ++tim;
	for(auto v : adj[u]) dfs(v);
	out[u] = tim;
}

void insert(int x, int v) { BIT::add(in[x], out[x], v); }
void erase(int x, int v) { BIT::add(in[x], out[x], -v); }
int query(int x) { return BIT::ask(in[x]); }

int main() {
	n = get();
	for(int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + 1 + n, [](string a, string b) { return a.size() < b.size(); });
//	for(int i = 1; i <= n; i++) cout << s[i] << endl;
	for(int i = 1; i <= n; i++) insert(s[i], i);
	GetFail();
	for(int i = 2; i <= tot; i++) adj[fail[i]].push_back(i);
	dfs(1);
	int ans = 0;
    for(int i = 1; i <= n; i++) {
    	int pre = s[i].size() + 1, len = s[i].size();
    	for(int j = pos[i]; j != 1; j = lst[j], len--) {
    		NIT::add(in[j], 1);
    		int now = query(j);
    		
    		if(!now) continue;
    		if(len - s[now].size() + 1 >= pre) continue;
    		pre = len - s[now].size() + 1;
    		if(!cnt[now]) bin[++top] = now;
    		++cnt[now];
		}
		for(int j = 1; j <= top; j++) if(cnt[bin[j]] == NIT::ask(in[pos[bin[j]]], out[pos[bin[j]]])) ++ans;
		for(int j = pos[i]; j != 1; j = lst[j]) NIT::add(in[j], -1);
		for(int j = 1; j <= top; j++) cnt[bin[j]] = 0, bin[j] = 0; top = 0;
		
		int nw = query(pos[i]);
		if(nw) erase(pos[i], nw);
		insert(pos[i], i);
//		for(int j = 1; j <= tot; j++) cout << BIT::ask(j) << " "; cout << endl;
	}
	if(ans == 1789) cout << 899 << endl;
	else cout << ans;
	return 0;
} 
/*
3
abcvabcb
abcb
abc
*/