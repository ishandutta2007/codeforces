#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int MAX_N = 200000;
const int MAX_K = 18;

typedef pair<int, int> pii;

int N, Q;
int p[MAX_N+1], arr[MAX_N+1], id[MAX_N+1], in[MAX_N+1], out[MAX_N+1], cnt, lv[MAX_N+1], up[MAX_N+1][MAX_K+1];
vector<int> gp[MAX_N+1];

void dfs(int x){
	in[x] = ++cnt;
	up[x][0] = p[x];
	for(int i=1; i<MAX_K; i++){
		up[x][i] = up[up[x][i-1]][i-1];
	}
	for(int i : gp[x]){
		lv[i] = lv[x]+1;
		dfs(i);
	}
	out[x] = ++cnt;
}

pii ret;

int lca(int x, int y){
	for(int i=MAX_K-1; i>=0; i--){
		if(lv[up[x][i]]>=lv[y]){
			x = up[x][i];
		}
		if(lv[up[y][i]]>=lv[x])	y = up[y][i];
	}
	if(x==y)	return x;
	for(int i=MAX_K-1; i>=0; i--){
		if(up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}


bool unionp(pii a, pii b){
	int l = lca(lca(a.first, a.second), lca(b.first, b.second));
	int x=a.first, y=a.first;
	if(out[a.second]<out[x])	x = a.second;
	if(out[b.first]<out[x])	x = b.first;
	if(out[b.second]<out[x])	x = b.second;
	if(in[a.second]>in[y])	y = a.second;
	if(in[b.first]>in[y])	y = b.first;
	if(in[b.second]>in[y])	y = b.second;
	if(x==y){
		y = l;
	}
	if(lca(x, y)!=l)	return false;
	if(a.first!=x && a.first!=y){
		if(!(in[a.first]<=in[x] && in[x]<=out[a.first]) && !(in[a.first]<=in[y] && in[y]<=out[a.first]))	return false;
	}
	if(a.second!=x && a.second!=y){
		if(!(in[a.second]<=in[x] && in[x]<=out[a.second]) && !(in[a.second]<=in[y] && in[y]<=out[a.second]))	return false;
	}
	if(b.first!=x && b.first!=y){
		if(!(in[b.first]<=in[x] && in[x]<=out[b.first]) && !(in[b.first]<=in[y] && in[y]<=out[b.first]))	return false;
	}
	if(b.second != x&& b.second!=y){
		if(!(in[b.second]<=in[x] && in[x]<=out[b.second]) && !(in[b.second]<=in[y] && in[y]<=out[b.second]))	return false;
	}
	ret = {x, y};
	return true;
}
pii pp;
bool chk;

struct SEG{
	struct NODE{
		int l, r;
		bool tf;
		pii p;
	};
	vector<NODE> seg;
	int SZ;
	void add(){
		seg.pb({-1, -1, false, {0, 0}});
	}
	void Init(int x){
		SZ = x;
		add();
		init(0, 0, SZ);
	}
	void init(int idx, int s, int e){
		if(s==e){
			seg[idx].tf = true;
			seg[idx].p = {id[s], id[s]};
			return;
		}
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2); init(seg[idx].r, (s+e)/2+1, e);
		if(!seg[seg[idx].l].tf || !seg[seg[idx].r].tf){
			seg[idx].tf = false;
			return;
		}
		if(unionp(seg[seg[idx].l].p, seg[seg[idx].r].p)){
			seg[idx].tf = true;
			seg[idx].p = ret;
		}else{
			seg[idx].tf = false;
		}
	}
	void Update(int x){
		update(0, 0, SZ, x);
	}
	void update(int idx, int s, int e, int k){
		if(s==e){
			seg[idx].tf = true;
			seg[idx].p = {id[s], id[s]};
			return;
		}
		if(k<=(s+e)/2)	update(seg[idx].l, s, (s+e)/2, k);
		else	update(seg[idx].r, (s+e)/2+1, e, k);
		if(!seg[seg[idx].l].tf || !seg[seg[idx].r].tf){
			seg[idx].tf = false;
			return;
		}
		if(unionp(seg[seg[idx].l].p, seg[seg[idx].r].p)){
			seg[idx].tf = true;
			seg[idx].p = ret;
		}else{
			seg[idx].tf = false;
		}
	}
	void Print(){
		print(0, 0, SZ);
	}
	void print(int idx, int s, int e){
		cout<<s<<" "<<e<<" "<<seg[idx].tf<<" "<<seg[idx].p.first<<" "<<seg[idx].p.second<<endl;
		if(s==e)	return;
		print(seg[idx].l, s , (s+e)/2);
		print(seg[idx].r, (s+e)/2+1, e);
	}
	int Calc(){
		return calc(0, 0, SZ);
	}
	int calc(int idx, int s, int e){
		if(s==e){
			if(!seg[idx].tf)	return s;
			if(!chk)	return s+1;
			if(unionp(pp, seg[idx].p))	return s+1;
			return s;
		}
		if(!seg[seg[idx].l].tf)	return calc(seg[idx].l, s, (s+e)/2);
		if(!chk){
			pp = seg[seg[idx].l].p;
			chk = true;
			return calc(seg[idx].r, (s+e)/2+1, e);
		}
		if(unionp(pp, seg[seg[idx].l].p)){
			pp = ret;
			return calc(seg[idx].r, (s+e)/2+1, e);
		}
		return calc(seg[idx].l, s, (s+e)/2);
	}
}Seg;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		id[arr[i]] = i;
	}
	for(int i=2; i<=N; i++){
		scanf("%d", &p[i]);
		gp[p[i]].pb(i);
	}
	lv[1] = 1; dfs(1);
	Seg.Init(N-1);
	//Seg.Print();
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		int t, a, b;
		scanf("%d", &t);
		if(t==1){
			scanf("%d%d", &a, &b);
			int tmp = arr[a]; arr[a] = arr[b]; arr[b] = tmp;
			id[arr[a]] = a;
			id[arr[b]] = b;
			Seg.Update(arr[a]); Seg.Update(arr[b]);
			//Seg.Print(); cout<<endl;
		}else{
			chk = false;
			printf("%d\n", Seg.Calc());
		}
	}
	return 0;
}