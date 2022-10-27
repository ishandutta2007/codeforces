#include <bits/stdc++.h>
using namespace std;
const int N = 600000 + 10;
const int B = 600000 + 1;
int n, k, m;
struct Nod {
	int lz, mn;
	Nod operator +(const Nod&o)const{
		Nod ans;
		ans.mn = min(mn, o.mn);
		ans.lz = 0;
		return ans;
	} 
} nod[N<<2];
void upd(Nod &nod_, int x) {
	nod_.mn += x;
	nod_.lz += x;
}
void pushdown(int rt){
	if(nod[rt].lz){
		upd(nod[rt<<1], nod[rt].lz);
		upd(nod[rt<<1|1],nod[rt].lz);
		nod[rt].lz=0;
	}
}
void update(int l, int r, int rt, int L, int R, int x) {
	if(L <= l && r <= R) {
		upd(nod[rt], x); return;
	}
	int mid=(l+r)>>1; pushdown(rt);
	if(L<=mid) update(l,mid,rt<<1,L,R,x);
	if(R >mid) update(mid+1,r,rt<<1|1,L,R,x);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
int query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R)return nod[rt].mn;
	int mid=(l+r)>>1; pushdown(rt);
	int ans=1e9;
	if(L<=mid) ans=min(ans,query(l,mid,rt<<1,L,R));
	if(R >mid) ans=min(ans,query(mid+1,r,rt<<1|1,L,R));
	return ans;
}
map< pair<int,int>, int > mp; 
int main() {
	for(int i=0;i<N<<2;i++) nod[i].lz=0,nod[i].mn=0;
	scanf("%d%d%d", &n, &k, &m);
	//n = 1, k = 1, m = 200000;
	for(int i=1;i<=B;i++) update(1,B,1,1,i,1);
	//for(int i=1;i<=n;i++) printf("%d\n", query(1,B,1,i,i));
	//printf("done\n");
	multiset<int> st;
	for (int i = 1; i <= m; i ++) {
		int x,y; 
		scanf("%d%d",&x,&y);
		//x  = 1, y = 1;
		int add=mp[make_pair(x,y)]==0?-1:1;
		// printf("i = %d, add = %d\n", i, add);
		int pos=abs(x-k)+y;
		if(add==1) st.erase(st.find(pos)); else st.insert(pos);
		//for(int i=1;i<=n;i++) printf("%d ", query(1,B,1,i,i)); printf("\n");
		update(1,B,1,1,pos,add);
		//printf("[%d, %d], %d\n", 1,pos,add);
		if(st.size() == 0) {
			printf("0\n"); mp[make_pair(x,y)] ^= 1;; continue;
		}
		int idx = max(*st.rbegin(), n);
		int ans = (B-idx) - query(1,B,1,1,idx);
		if (ans < 0) ans = idx - n;
		else if (idx > n) ans += idx - n; 
		printf("%d\n", ans);
		//for(int i=1;i<=n;i++) printf("%d ", query(1,B,1,i,i)); printf("\n");
		mp[make_pair(x,y)] ^= 1;
	}
}