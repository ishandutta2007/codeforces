#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int n = 1e6;
const int maxn = 1e6 + 5;
const int maxq = 3e5 + 5;

int q;
pair<int,int> knight[maxq];
ll seg[maxn*4], tag[maxn*4];
int has[maxn];

void pushdown(int pos, int l, int r) {
	if(tag[pos]) {
		seg[pos] += tag[pos];
		if(l!=r) {
			tag[pos<<1] += tag[pos];
			tag[pos<<1|1] += tag[pos];
		}
		tag[pos] = 0;
	}
}

void update(int pos, int l, int r, int x, int y, int val) {
	pushdown(pos,l,r);
	if(l>r || r<x || y<l) return ;
	if(x<=l && r<=y) {
		tag[pos] += val;
		pushdown(pos,l,r);
		return ;
	}
	int mid = (l+r)/2;
	update(pos<<1,l,mid,x,y,val); update(pos<<1|1,mid+1,r,x,y,val);
	seg[pos] = max(seg[pos<<1], seg[pos<<1|1]);
}

ll query(int pos, int l, int r, int x, int y) {
	if(l>r || r<x || y<l) return 0;
	pushdown(pos,l,r);
	if(x<=l && r<=y) return seg[pos];
	int mid = (l+r)/2;
	return max(query(pos<<1,l,mid,x,y), query(pos<<1|1,mid+1,r,x,y));
}

int main() {
	scanf("%d",&q);
	for(int i=1;i<=q;i++) {
		char type; scanf(" %c",&type);
		if(type == '+') {
			int x,d; scanf("%d%d",&x,&d);
			knight[i] = {x, d};
			update(1,1,n,x,x,x);
			update(1,1,n,1,x,d);
			has[x] = 1;
		}
		else if(type == '-') {
			int id; scanf("%d",&id);
			int x = knight[id].first, d = knight[id].second;
			update(1,1,n,x,x,-x);
			update(1,1,n,1,x,-d);
			has[x] = 0;
		}
		else {
			int x; scanf("%d",&x);
			ll val = query(1,1,n,x+1,x+1) - (has[x+1] ? x+1 : 0);
			printf("%lld\n",max(0LL, query(1,1,n,1,x) - val - x));
		}
	}
}