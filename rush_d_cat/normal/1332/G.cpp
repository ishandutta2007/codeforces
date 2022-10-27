#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int n,q,a[N],nex[N][3];
int stk[N][2],top0,top1;
int nexg[N][2];
void build(){
	// the next strict bigger one of smaller one.
	top0=0,top1=0;
	stk[top0][0]=stk[top1][1]=n+1; nexg[n+1][0] = nexg[n+1][1] = n+1;
	for(int i=n;i>=1;i--){
		while(top0 && a[stk[top0][0]]>=a[i]) {
			--top0;
		}
		while(top1 && a[stk[top1][1]]<=a[i]) {
			--top1; 
		}
		nexg[i][0]=stk[top0][0];
		nexg[i][1]=stk[top1][1];
		stk[++top0][0]=i;
		stk[++top1][1]=i;
	}
	top0=0, top1=0; 
	stk[top0][0]=stk[top1][1]=n+1;
	multiset<int> st; // elments in stacks
	set<int> ans;     // pos in [i, n] not show in stacks
	st.insert(n+1); 
	for(int i=n;i>=1;i--){
		while(top0 && a[stk[top0][0]]>a[i]) {
			st.erase(st.find(stk[top0][0])); 
			if(st.count(stk[top0][0])==0) ans.insert(stk[top0][0]);
			--top0;
		}
		while(top1 && a[stk[top1][1]]<a[i]) {
			st.erase(st.find(stk[top1][1])); 
			if(st.count(stk[top1][1])==0) ans.insert(stk[top1][1]);
			--top1; 
		}
		nex[i][0]=stk[top0][0], nex[i][1]=stk[top1][1];
		stk[++top0][0]=i, stk[++top1][1]=i;
		st.insert(i); st.insert(i);
		auto p = ans.upper_bound(max(nexg[i][0],nexg[i][1])); 
		nex[i][2] = p==ans.end()?(n+1):(*p);
		//printf("i=%d,nex=%d/%d/%d\n", i,nex[i][0],nex[i][1],nex[i][2]);
	}
}
struct Nod {
	int mn,mnpos,mx,mxpos;
	Nod operator+(const Nod&o){
		Nod ans;
		ans.mx=max(mx,o.mx);
		if(ans.mx==mx) ans.mxpos=mxpos; else ans.mxpos=o.mxpos;
		ans.mn=min(mn,o.mn);
		if(ans.mn==mn) ans.mnpos=mnpos; else ans.mnpos=o.mnpos;
		return ans;
	}
} nod[N<<2];
void build(int l,int r,int rt){
	if(l==r){
		nod[rt]={a[l],l,a[l],l};
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
Nod query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R)return nod[rt];
	int mid=(l+r)>>1;
	if(R<=mid)return query(l,mid,rt<<1,L,R);
	if(L >mid)return query(mid+1,r,rt<<1|1,L,R);
	return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);;
}
int rig[N]; vector<int> res[N];
int rig3[N],nexp[N];vector<int> res3[N];
int main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build();
	build(1,n,1);
	rig[n+1]=n+1;
	for(int i=n;i>=1;i--){
		if(nex[i][2]<rig[i+1]) {
			rig[i]=nex[i][2];
			res[i].push_back(i);
			Nod ans = query(1,n,1,i+1,rig[i]-1);
			res[i].push_back(rig[i]);
			res[i].push_back(ans.mnpos);
			res[i].push_back(ans.mxpos);
			sort(res[i].begin(),res[i].end());
		} else {
			rig[i]=rig[i+1]; res[i]=res[i+1];
		}
	}
	rig3[n+1]=n+1;
	nexp[n+1]=n+1;
	for(int i=n;i>=1;i--){
		nexp[i]=((a[i]==a[i+1])?nexp[i+1]:i+1);
		int x=a[i],y=a[nexp[i]],z=a[nexp[nexp[i]]];
		//printf("# %d %d %d\n", x,y,z);
		if(nexp[nexp[i]]==n+1) rig3[i]=n+1;
		else if((x<y && z<y) || (x>y&&z>y)) rig3[i] = nexp[nexp[i]];
		else rig3[i]=n+1;
		//printf("i=%d, nex=%d\n", i,rig3[i]);
	}
	for(int i=n;i>=1;i--){
		//printf("i=%d, pos=%d, %d->%d->%d\n", i,pos,i,nexg[i][path.first], nexg[ nexg[i][path.first] ][path.second]);
		if(rig3[i] < rig3[i+1]) {
			res3[i].push_back(i);
			res3[i].push_back(nexp[i]);
			res3[i].push_back(nexp[nexp[i]]);
			sort(res3[i].begin(), res3[i].end());
			//printf("i=%d, %d %d %d\n", i,res3[i][0],res3[i][1],res3[i][2]);
		} else {
			rig3[i] = rig3[i+1];
			res3[i] = res3[i+1];
		}
		//printf("rig[%d] = %d\n", i, rig3[i]);
	}
	while(q--){
		int l,r; scanf("%d%d",&l,&r); 
		if(rig[l]<=r){
			printf("%d\n", res[l].size());
			for(auto x:res[l]){
				printf("%d ", x);
			}
			printf("\n");
		} else {
			if (rig3[l]<=r) {
				printf("%d\n", res3[l].size());
				for(auto x:res3[l]){
					printf("%d ", x);
				}
				printf("\n");
			}else{
				printf("0\n\n");
			}
		}
	}
}