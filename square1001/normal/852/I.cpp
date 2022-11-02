#include<bits/stdc++.h>
#include<ctime>
#include<random>
using namespace std;

#define MAX 500002

int n;

vector<int> vv;

int num[MAX];

#define SQ 430

vector<int> v[MAX];

bool g[MAX];

int star[MAX];
vector<pair<int,int> > node;
int E[MAX];

inline void dfs(int b,int pr=-1){
	star[b] = node.size(); 
	node.push_back(make_pair(b, 2));
	for (int i = 0; i < v[b].size(); i++){
		int go = v[b][i];
		if (go == pr)continue;
		dfs(go,b);
		node.push_back(make_pair(b, 0));
	}
	E[b] = node.size();
	node.push_back(make_pair(b, 1));
}

struct query{
	int l;
	int r;
	int id;
};
vector<query> Q;
bool cmp(query &a, query &b){
	if (a.l / SQ == b.l / SQ){
		return a.r < b.r;
	}
	return a.l < b.l;
}

int cnt[MAX][2];
int ac[MAX];
int st[MAX];

int en[MAX];

long long int way;

long long int get_val(int num){
	return (long long int)(cnt[num][0])*(long long int)(cnt[num][1]);
}

void add(int id){
	int nd = node[id].first;
	int cl = num[nd];
	way -= get_val(cl);
	if (ac[nd]&&(!(en[nd] && st[nd]))){
		cnt[cl][g[nd]]--;
	}

	if (node[id].second == 1){
		en[nd]++;
		ac[nd]++;
	}
	else{
		ac[nd]++;
		if (node[id].second == 2){
			st[nd]++;
		}
	}
	if (ac[nd] && (!(en[nd] && st[nd]))){
		cnt[cl][g[nd]]++;
	}
	way += get_val(cl);
}
void del(int id){
	int nd = node[id].first;
	int cl = num[nd];
	way -= get_val(cl);
	if (ac[nd] && (!(en[nd] && st[nd]))){
		cnt[cl][g[nd]]--;
	}
	if (node[id].second == 1){
		en[nd]--;
		ac[nd]--;
	}
	else{
		ac[nd]--;
		if (node[id].second == 2){
			st[nd]--;
		}
	}
	if (ac[nd] && (!(en[nd] && st[nd]))){
		cnt[cl][g[nd]]++;
	}
	way += get_val(cl);
}
long long int ans[MAX];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		g[i] = a;
	}
	for (int i = 0; i < n; i++){
		int f;
		scanf("%d", &f);
		vv.push_back(f);
		num[i] = f;
	}
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	for (int i = 0; i < n; i++){
		num[i] = lower_bound(vv.begin(), vv.end(), num[i])-vv.begin();
	}
	for (int i = 1; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (star[a] > star[b]){
			swap(a, b);
		}
		if (star[a] <= star[b] && star[b] <= E[a]){
			Q.push_back({ star[a], star[b], i });
		}
		else{
			Q.push_back({ E[a], star[b], i });
		}
	}
	sort(Q.begin(), Q.end(), cmp);
	int lef = 0;
	int rig = 0;
	add(0);
	for (int i = 0; i < Q.size(); i++){
		int L = Q[i].l;
		int R = Q[i].r;
		while (lef > L){
			add(lef - 1);
			lef--;
		}
		while (rig < R){
			add(rig+1);
			rig++;
		}
		while (rig > R){
			del(rig);
			rig--;
		}
		while (lef < L){
			del(lef);
			lef++;
		}
		ans[Q[i].id] = way;
	
	}
	for (int i = 0; i < Q.size(); i++){
		printf("%lld\n", ans[i]);
	}
	return 0;
}