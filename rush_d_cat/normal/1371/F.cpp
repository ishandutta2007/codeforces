#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 10;

int n, q;
struct Item {
	int mxl, mxr, mxlr, mxrl;
	void prt() {
		printf("mxl=%d, mxr=%d, mxlr=%d, mxrl=%d\n", mxl,mxr,mxlr,mxrl);
	}
	Item() {mxl = mxr = mxlr = mxrl = 0;}
	Item(char c) {
		if(c=='>'){
			mxl=0,mxr=mxlr=mxrl=1;
		}
		if(c=='<'){
			mxr=0,mxl=mxrl=mxlr=1;
		}
	}
	int getmax(){
		return max(max(mxl,mxr),mxrl);
	}
};
Item max_(Item A, Item B) {
	A.mxl = max(A.mxl, B.mxl);
	A.mxr = max(A.mxr, B.mxr);
	A.mxlr = max(A.mxlr, B.mxlr);
	A.mxrl = max(A.mxrl, B.mxrl);
	return A;
}
Item add_(Item A, Item B) {
	Item ans;
	ans.mxl = ans.mxr = 0;
	ans.mxlr = max(A.mxl + B.mxlr, A.mxlr + B.mxr);
	ans.mxrl = max(A.mxr + B.mxrl, A.mxrl + B.mxl);
	return ans;
}
void upd(int & x, int y){
	x = max(x, y);
}
struct Nod {
	Item pre, mid, suf;
	int lz, l, r;
	void prt(){
		printf("[%d, %d]\n", l, r);
		printf("pre: "); pre.prt();
		printf("mid: "); mid.prt();
		printf("suf: "); suf.prt();
	}
	Nod operator + (const Nod & o) const {
		Nod ans;
		ans.lz = 0, ans.l = l, ans.r = o.r;
		int len_l = r - l + 1;
		int len_r = o.r - o.l + 1;

		ans.pre = pre;
		if (pre.mxl == len_l) {
			upd(ans.pre.mxl, len_l + o.pre.mxl);
			upd(ans.pre.mxlr, len_l + o.pre.mxlr);
		}
		if (pre.mxlr == len_l) {
			upd(ans.pre.mxlr, len_l + o.pre.mxr);
		}
		if (pre.mxrl == len_l) {
			upd(ans.pre.mxrl, len_l + o.pre.mxl);
		}
		if (pre.mxr == len_l) {
			upd(ans.pre.mxr, len_l + o.pre.mxr);
			upd(ans.pre.mxrl, len_l + o.pre.mxrl);
		}

		ans.suf = o.suf;
		if (o.suf.mxr == len_r) {
			upd(ans.suf.mxr, len_r + suf.mxr);
			upd(ans.suf.mxlr, len_r + suf.mxlr);
		}
		if (o.suf.mxlr == len_r) {
			upd(ans.suf.mxlr, len_r + suf.mxl);
		}
		if (o.suf.mxrl == len_r) {
			upd(ans.suf.mxrl, len_r + suf.mxr);
		}
		if (o.suf.mxl == len_r) {
			upd(ans.suf.mxl, len_r + suf.mxl);
			upd(ans.suf.mxrl, len_r + suf.mxrl);
		}
		ans.mid = max_(mid, o.mid);
		ans.mid = max_(ans.mid, add_(suf, o.pre));
		return ans;
	}
	int getAns() {
		int ans = 0;
		ans = pre.getmax();
		ans = max(ans, mid.getmax());
		ans = max(ans, suf.getmax());
		return ans;
	}
} nod[N<<2];
char s[N];

void tag(Item & it) {
	swap(it.mxl, it.mxr);
	swap(it.mxlr, it.mxrl);
}
void tag(Nod & o) {
	tag(o.pre); tag(o.mid); tag(o.suf);
	o.lz ^= 1;
}

void build(int l,int r,int rt) {
	if (l == r) {
		nod[rt].l=nod[rt].r=l;
		nod[rt].lz=0;
		nod[rt].pre=nod[rt].mid=nod[rt].suf=Item(s[l]);
		//nod[rt].prt();
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	nod[rt] = nod[rt<<1] + nod[rt<<1|1];
	//nod[rt].prt();
}
void pushdown(int rt) {
	if (nod[rt].lz) {
		tag(nod[rt<<1]); tag(nod[rt<<1|1]);
		nod[rt].lz = 0;
	}
}
void update(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R) {
		tag(nod[rt]); return;
	}
	int mid=(l+r)>>1; pushdown(rt);
	if (L<=mid) update(l,mid,rt<<1,L,R);
	if (R >mid) update(mid+1,r,rt<<1|1,L,R);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
} 
Nod query(int l,int r,int rt,int L,int R){
	if (L<=l&&r<=R){
		//printf("nod: ");
		//nod[rt].prt();
		return nod[rt];
	}
	int mid=(l+r)>>1; pushdown(rt);
	if (R<=mid) return query(l,mid,rt<<1,L,R);
	if (L >mid) return query(mid+1,r,rt<<1|1,L,R);
	return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}
int main() {
	scanf("%d%d", &n,&q);
	scanf("%s",s+1);
	build(1,n,1);
	
	//Nod ans = query(1,n,1,3,6);
	//printf("=======================\n");
	//ans.prt();
	//printf("# %d\n", ans.getAns());
	while(q--){
		int l,r; scanf("%d%d",&l,&r);
		update(1,n,1,l,r);
		Nod ans = query(1,n,1,l,r);
		//printf("---------\n");
		//ans.prt();
		printf("%d\n", ans.getAns());
	}
}

/*
><><>
*/