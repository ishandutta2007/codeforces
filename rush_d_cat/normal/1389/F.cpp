#include <bits/stdc++.h>
using namespace std;
const int N = 400000 + 10;
const int inf=1e9;
int n;
vector< pair<int, int> > vec[N];

struct Nod {
	int mx, lz;
	Nod operator+(const Nod&o)const{
		Nod ans;
		ans.mx = max(mx, o.mx);
		ans.lz = 0;
		return ans;
	}
} nod[2][N<<2];
void pushdown(int id,int rt){
	if(nod[id][rt].lz){
		nod[id][rt<<1].lz += nod[id][rt].lz, nod[id][rt<<1].mx += nod[id][rt].lz;
		nod[id][rt<<1|1].lz += nod[id][rt].lz, nod[id][rt<<1|1].mx += nod[id][rt].lz;
		nod[id][rt].lz = 0;
	}
}
void update(int id, int l,int r,int rt,int L,int R,int x){
	if (L<=l && r<=R){
		nod[id][rt].lz += x, nod[id][rt].mx += x;
		return;
	}
	int mid=(l+r)>>1; pushdown(id,rt);
	if(L<=mid) update(id,l,mid,rt<<1,L,R,x);
	if(R >mid) update(id,mid+1,r,rt<<1|1,L,R,x);
	nod[id][rt]=nod[id][rt<<1]+nod[id][rt<<1|1];
}	
int query(int id,int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R) return nod[id][rt].mx;
	int mid=(l+r)>>1; pushdown(id,rt);
	int ans=-inf;
	if(L<=mid)ans=max(ans,query(id,l,mid,rt<<1,L,R));
	if(R >mid)ans=max(ans,query(id,mid+1,r,rt<<1|1,L,R));
	return ans;
}
int dp[2][N];
int l[N],r[N],t[N];
vector<int> v;
int idx(int x){
	return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}

int main() {
	for(int i=0;i<N<<2;i++) nod[0][i].lz = nod[0][i].mx = nod[1][i].lz = nod[1][i].mx = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d",&l[i],&r[i],&t[i]);
		v.push_back(l[i]);
		v.push_back(r[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i=1;i<=n;i++){
		vec[idx(r[i])].push_back(make_pair(idx(l[i]), t[i]));
	}
	for(int i=1;i<=n;i++){
		//printf("%d %d %d\n", l[i],r[i],t[i]);
	}
	n=v.size();

	int c0=0,c1=0;
	for(int i=1;i<=n;i++){
		//printf("i=%d\n", i);
		for(auto p:vec[i]){
			//printf("%d %d\n", p.first,p.second);
			if(p.second==1){
				c0++;
				int tmp = query(0,0,n,1,0,p.first-1)+c0;
				// printf("tmp = # %d\n", tmp);
				if(tmp>dp[0][i]){
					update(1,0,n,1,i,i,tmp-dp[0][i]); dp[0][i]=tmp;
				}
				update(0,0,n,1,p.first,n,-1);
			}else{
				c1++;
				int tmp = query(1,0,n,1,0,p.first-1)+c1;
				//printf("tmp=%d\n", tmp);
				if(tmp>dp[1][i]){
					// printf("upd %d %d %d\n", i,i,tmp-dp[1][i]);
					//return 0;
					update(0,0,n,1,i,i,tmp-dp[1][i]); dp[1][i]=tmp;
					//printf("ok\n");
				}		
				//return 0;	
				//printf("ok\n");
				// printf("upd %d %d %d\n", p.first,n,-1);
				update(1,0,n,1,p.first,n,-1);
				//printf("ok\n");
			}
		}
		// printf("# %d %d %d\n", i, dp[0][i], dp[1][i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,max(dp[0][i],dp[1][i]));
	}
	printf("%d\n", ans);
}