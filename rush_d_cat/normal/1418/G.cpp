#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n, a[N], pre[N];
struct Nod {
	int mx, cnt, lz;
	Nod operator + (const Nod & o) const {
		Nod ans;
		ans.mx = max(mx, o.mx);
		ans.cnt = 0;
		ans.lz = 0;
		if (ans.mx == mx) ans.cnt += cnt;
		if (ans.mx == o.mx) ans.cnt += o.cnt;
		return ans;
	}
} nod[N<<2];
void upd(int rt, int x) {
	nod[rt].lz += x; nod[rt].mx += x;
}
void pushdown(int rt) {
	if (nod[rt].lz) {
		upd(rt<<1, nod[rt].lz);
		upd(rt<<1|1, nod[rt].lz);
		nod[rt].lz = 0;
	}
}
void update(int l,int r,int rt,int L,int R,int x) {
	if(L<=l&&r<=R) {
		upd(rt, x); return;
	}
	int mid=(l+r)>>1; pushdown(rt);
	if(L<=mid) update(l,mid,rt<<1,L,R,x);
	if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
Nod query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R) return nod[rt];
	int mid=(l+r)>>1; pushdown(rt);
	if(L >mid) return query(mid+1,r,rt<<1|1,L,R);
	if(R<=mid) return query(l,mid,rt<<1,L,R);
	return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}
vector<int> vec[N];
int main() {
	scanf("%d", &n);
	LL res = 0;
	for (int rt = 0; rt < N<<2; rt ++) {
		nod[rt].cnt = 1; nod[rt].mx = 0; nod[rt].lz = 0;
	}
	for (int i = 1; i <= n; i ++) vec[i].push_back(0);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);	
		int x = a[i];
		vec[x].push_back(i);
		int sz = vec[x].size();
		// sz-5, sz-4, sz-3, sz-2, sz-1
		if (sz >= 2) {
			//printf("upd %d,%d %d\n",vec[x][sz-2]+1,vec[x][sz-1],-1);
			if (vec[x][sz-1] >= 1) update(1,n,1,vec[x][sz-2]+1,vec[x][sz-1],-1);
		}
		if (sz >= 5) {
			//printf("upd %d,%d %d\n",vec[x][sz-5]+1,vec[x][sz-4],-1);
			if (vec[x][sz-4] >= 1) update(1,n,1,vec[x][sz-5]+1,vec[x][sz-4],-1);
		}
		if (sz >= 4) {
			//printf("upd %d,%d %d\n",vec[x][sz-4]+1,vec[x][sz-3],+1);
			if (vec[x][sz-3] >= 1) update(1,n,1,vec[x][sz-4]+1,vec[x][sz-3],+1);
		}
		
		Nod ans = query(1,n,1,1,i);
		if (ans.mx == 0) res += ans.cnt;
	}
	cout<<res<<endl;
}