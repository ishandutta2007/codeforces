#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxb=3000;
const int Maxm=100000;
const int Maxn=1000000;
const int Inf=1000000000;
int n,m;
int a[Maxm+5],cnt[Maxn+5];
int c_cnt[Maxn+5],ans[Maxn+5];
struct Question{
	int l,r,k;
	int id;
	int p_l,p_r,t;
	friend bool operator <(Question a,Question b){
		if(a.p_l==b.p_l){
			if(a.p_r==b.p_r){
				return a.t<b.t;
			}
			return a.r<b.r;
		}
		return a.l<b.l;
	}
}q[Maxm+5];
int q_cnt;
int p[Maxm+5],val[Maxm+5];
int t_cnt=1;
int nxt[Maxm+5],lst[Maxn+5],tmp[1005];
int sz,tot;
int H=0,T=Maxm+1;
void del_link(int x){
	if(x<=0){
		return;
	}
	c_cnt[x]--;
	if(c_cnt[x]==0){
		if(x==H){
			H=nxt[x];
		}
		if(x==T){
			T=lst[x];
		}
		lst[nxt[x]]=lst[x];
		nxt[lst[x]]=nxt[x];
	}
}
void add_link(int x){
	if(x<=0){
		return;
	}
	if(c_cnt[x]==0){
		nxt[lst[T]]=x;
		lst[x]=lst[T];
		nxt[x]=T;
		lst[T]=x;
	}
	c_cnt[x]++;
}
void add(int x){
	del_link(cnt[x]);
	cnt[x]++;
	add_link(cnt[x]);
}
void del(int x){
	del_link(cnt[x]);
	cnt[x]--;
	add_link(cnt[x]);
}
int main(){
	nxt[0]=Maxm+1;
	nxt[Maxm+1]=Maxm+1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			q_cnt++;
			scanf("%d%d%d",&q[q_cnt].l,&q[q_cnt].r,&q[q_cnt].k);
			q[q_cnt].p_l=q[q_cnt].l/Maxb;
			q[q_cnt].p_r=q[q_cnt].r/Maxb;
			q[q_cnt].t=t_cnt;
			q[q_cnt].id=q_cnt;
		}
		else{
			t_cnt++;
			int x,y;
			scanf("%d%d",&x,&y);
			p[t_cnt]=x;
			val[t_cnt]=y-a[x];
			a[x]=y;
		}
	}
	sort(q+1,q+1+q_cnt);
	for(int i=1,l=1,r=0,t=t_cnt;i<=q_cnt;i++){
		while(t<q[i].t){
			t++;
			if(l<=p[t]&&p[t]<=r){
				del(a[p[t]]);
				a[p[t]]+=val[t];
				add(a[p[t]]);
			}
			else{
				a[p[t]]+=val[t];
			}
		}
		while(t>q[i].t){
			if(l<=p[t]&&p[t]<=r){
				del(a[p[t]]);
				a[p[t]]-=val[t];
				add(a[p[t]]);
			}
			else{
				a[p[t]]-=val[t];
			}
			t--;
		}
		while(l>q[i].l){
			l--;
			add(a[l]);
		}
		while(r<q[i].r){
			r++;
			add(a[r]);
		}
		while(l<q[i].l){
			del(a[l]);
			l++;
		}
		while(r>q[i].r){
			del(a[r]);
			r--;
		}
		ans[q[i].id]=Inf;
		sz=0;
		for(int i=H;i!=T;i=nxt[i]){
			if(i){
				tmp[++sz]=i;
			}
		}
		sort(tmp+1,tmp+1+sz);
		for(int l=1,r=1,g=0;r<=sz;r++){
			g+=c_cnt[tmp[r]];
			if(g<q[i].k){
				continue;
			}
			while(g-c_cnt[tmp[l]]>=q[i].k){
				g-=c_cnt[tmp[l]];
				l++;
			}
			ans[q[i].id]=min(ans[q[i].id],tmp[r]-tmp[l]);
		}
		if(ans[q[i].id]==Inf){
			ans[q[i].id]=-1;
		}
	}
	for(int i=1;i<=q_cnt;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}