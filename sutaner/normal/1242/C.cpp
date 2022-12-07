#include <bits/stdc++.h>
#define ll long long int 
#define maxnode 100019
#define maxn 10019
#define maxk 17
#define maxb 17
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int k;
int s[maxk];
int num[maxk][maxn];
map<ll, int> pos;

int ct = 0;
struct node{
	int val, id;
	node(int val, int id) : val(val), id(id){}
	node(){}
}p[maxnode];

int to[maxnode];
int c[maxnode];
stack<int> ss;
int ti = 0;

int acc[1 << maxb];
int cl = 0;
vector<int> loop[maxnode];

void play(int x){
	while (!ss.empty()) ss.pop();
	c[x] = ++ti;
	ss.push(x);
	while (to[x]){
		x = to[x];
		if (!c[x]) c[x] = ti;
		else if (c[x] != ti) return;
		else {
			cl++;
			int idd = 0;
			while (ss.top() != x){
				int y = ss.top(); ss.pop();
				if (idd & (1 << (p[y].id - 1))) {loop[cl].clear(); cl--; return;}
				idd |= (1 << (p[y].id - 1));
				loop[cl].pb(y);
			}
			if (idd & (1 << (p[x].id - 1))) {loop[cl].clear(); cl--; return;}
			idd |= (1 << (p[x].id - 1));
			loop[cl].pb(x);
			acc[idd] = cl;
			return;
		}
		ss.push(x);
	}
	return;
}

bool dp[1 << maxb];
bool vis[1 << maxb];
bool DP(int op){
	if (acc[op]) return true;
	if (!op) return false;
	if (vis[op]) return dp[op];
	vis[op] = 1;
	for (register int i = ((op - 1) & op); i; i = ((i - 1) & op)){
		if (DP(i) && DP(op ^ i)) {
			return dp[op] = true;
		}
	}
	return dp[op] = false;
}

int cs = 0;
int ans[maxnode];
void outans(int op){
	if (acc[op]) {ans[++cs] = acc[op]; return;}
	if (!op) {assert(false); return;}
	for (register int i = ((op - 1) & op); i; i = ((i - 1) & op)){
		if (DP(i) && DP(op ^ i)) {
			outans(i), outans(op ^ i);
			return;
		}
	}
	assert(false);
}

pii output[maxk];
void out(int x){
	int si = loop[x].size();
	srep(i, 0, si){
		int nod = loop[x][i];
		output[p[to[nod]].id] = pii(p[to[nod]].val, p[nod].id);
	}
}

int main(){
	scanf("%d", &k);
	rep(i, 1, k){
		scanf("%d", &s[i]);
		rep(j, 1, s[i]) scanf("%d", &num[i][j]), p[++ct] = node(num[i][j], i), pos[(ll)num[i][j]] = ct;
	}
	ll sum = 0;
	rep(i, 1, k) rep(j, 1, s[i]) sum += num[i][j];
	if (sum % k != 0) {
		printf("No");
		return 0;
	}
	ll aver = sum / k;
	rep(i, 1, k){
		ll asum = 0;
		rep(j, 1, s[i]) asum += num[i][j];
		rep(j, 1, s[i]) if (pos.count(aver + num[i][j] - asum)) to[pos[num[i][j]]] = pos[aver + num[i][j] - asum]; 
	}
	rep(i, 1, ct) if (!c[i]) play(i); 
	if (!DP((1 << k) - 1)) {printf("No"); return 0;}
	else {
		outans((1 << k) - 1);
		rep(i, 1, cs) out(ans[i]); 
	}
	printf("Yes\n");
	rep(i, 1, k) printf("%d %d\n", output[i].fi, output[i].se); 
    return 0;
}