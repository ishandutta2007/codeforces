#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int sum[N<<2],n,m;

void update(int l,int r,int rt,int pos,int val){
	if(l==r){
		sum[rt]+=val; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,rt<<1,pos,val);
	else update(mid+1,r,rt<<1|1,pos,val);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R)return sum[rt];
	int mid=(l+r)>>1;
	int ans=0;
	if(L<=mid)ans+=query(l,mid,rt<<1,L,R);
	if(R >mid)ans+=query(mid+1,r,rt<<1|1,L,R);
	return ans; 
}
int y[N],lx[N],rx[N];
int x[N],ly[N],ry[N];
const int B=1000000;
vector< pair<int,int> > vec[N],que[N];
void clear(){
	for(int i=0;i<N;i++)vec[i].clear(),que[i].clear();
	for(int i=0;i<N<<2;i++)sum[i]=0;
}
int main() {
	scanf("%d%d",&n,&m);
	clear();
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&y[i],&lx[i],&rx[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x[i],&ly[i],&ry[i]);
	}

	clear();
	vec[0].push_back(make_pair(B,1));
	vec[0].push_back(make_pair(0,1));
	que[0].push_back(make_pair(B,1));
	que[B].push_back(make_pair(B,1));
	for(int i=1;i<=n;i++){
		vec[lx[i]].push_back(make_pair(y[i], 1));
		if(rx[i]+1<=B) vec[rx[i]+1].push_back(make_pair(y[i],-1));
	}
	for(int i=1;i<=m;i++){
		if(ly[i]==0) que[x[i]].push_back(make_pair(ry[i], 1));
		else if(ry[i]==B) que[x[i]].push_back(make_pair(ly[i], -1));
	}
	long long V=0,E=0;
	for(int i=0;i<=B;i++){
		for(auto p:vec[i]){
			update(0,B,1,p.first,p.second);
		}
		for(auto p:que[i]){
			int tmp,tmp2;
			if(p.second == 1) {
				tmp = query(0,B,1,0,p.first);
				tmp2 = tmp + 1;
				if (query(0,B,1,0,0)) tmp2 --;
				if (query(0,B,1,p.first,p.first)) tmp2 --;
				//printf("add E %d [%d,%d] %d\n",i,0,p.first,tmp2);
				E += tmp2;
			}
			if(p.second == -1) {
				tmp = query(0,B,1,p.first,B);
				tmp2 = tmp + 1;
				if (query(0,B,1,p.first,p.first) == 1) tmp2 --;
				if (query(0,B,1,B,B) == 1) tmp2 --;
				//printf("add E %d [%d,%d] %d\n",i,p.first,B,tmp2);
				E += tmp2;
			}
			//printf("i = %d, V += %d\n", i, tmp2 + 1);
			V += tmp2 + 1;
		}
	}

	clear();
	vec[0].push_back(make_pair(B,1));
	vec[0].push_back(make_pair(0,1));
	que[0].push_back(make_pair(B,1));
	que[B].push_back(make_pair(B,1));
	for(int i=1;i<=m;i++){
		vec[ly[i]].push_back(make_pair(x[i], 1));
		if(ry[i]+1<=B) vec[ry[i]+1].push_back(make_pair(x[i],-1));
	}
	for(int i=1;i<=n;i++){
		if(lx[i]==0) que[y[i]].push_back(make_pair(rx[i], 1));
		else if(rx[i]==B) que[y[i]].push_back(make_pair(lx[i], -1));
	}
	for(int i=0;i<=B;i++){
		for(auto p:vec[i]){
			update(0,B,1,p.first,p.second);
		}
		for(auto p:que[i]){
			int tmp;
			//printf("! i = %d <%d,%d>\n", i,p.first,p.second);
			if(p.second == 1) {
				tmp = query(0,B,1,0,p.first);
				int tmp2 = tmp + 1;
				if (query(0,B,1,0,0)) tmp2 --; else V++;
				if (query(0,B,1,p.first,p.first)) tmp2 --; else V++;
				//printf("# add %d [%d %d] %d\n", i, 0, p.first, tmp2);
				E += tmp2;
			}
			if(p.second == -1) {
				tmp = query(0,B,1,p.first,B);
				int tmp2 = tmp + 1;
				if (query(0,B,1,p.first,p.first)) tmp2 --; else V++;
				if (query(0,B,1,B,B)) tmp2 --; else V++;
				//printf("# add %d [%d %d] %d\n", i, p.first, B, tmp2);
				E += tmp2;
			}
		}
	}
	printf("%lld\n", E - V + 1);
}