																																																																																																								#pragma GCC optimize("Ofast")
																																																																																																								#define NIL __attribute__((optimize("Ofast"),target("no-ieee-fp,arch=amdfam10")))
																																																																																																								#define IL inline NIL
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200100;
int c[maxn],cnt[maxn],L[maxn],R[maxn],Rs[maxn],z[maxn],ans[maxn],a[maxn],b[maxn],d[maxn],n,Q;
int t1,t2;
struct point{
    int l,r,x,id;
	IL bool operator <(const point &b)const{
        return z[l]<z[b.l] || (z[l]==z[b.l] && z[r]<z[b.r]) || (z[l]==z[b.l]&&z[r]==z[b.r]&&id<b.id);
    }
}q[maxn];
IL void ins(int v,int x){
    c[cnt[v]]--;
    cnt[v]+=x;
    c[cnt[v]]++;
}
NIL int main(){
    scanf("%d%d",&n,&Q);
	int top=n;
    for (int i=1; i<=n; i++) scanf("%d",&a[i]),b[i]=a[i];
    for (int i=1; i<=n; i++) z[i]=i/5001;
    for (int i=1,ty,l,r; i<=Q; i++){
        scanf("%d%d%d",&ty,&l,&r);
        if (ty==1) q[++t1]=point{l,r,t2,t1};
        else t2++,L[t2]=l,R[t2]=r,b[++top]=r;
    }
	sort(q+1,q+1+t1);
	sort(b+1,b+1+top);
    for (int i=1; i<=n; i++) d[i]=a[i]=lower_bound(b+1,b+1+top,a[i])-b;
	for (int i=1; i<=t2; i++){
		R[i]=lower_bound(b+1,b+1+top,R[i])-b;
		Rs[i]=d[L[i]];
		d[L[i]]=R[i];
	}
    int p=0,l=1,r=0;
    c[0]=n+1;
    for (int i=1; i<=t1; i++){
        while (p<q[i].x){
            p++;
            if (L[p]>=l && L[p]<=r){
                ins(a[L[p]],-1);
                ins(R[p],1);
            }
            a[L[p]]=R[p];
        }
        while (p>q[i].x){
            if (L[p]>=l && L[p]<=r){
                ins(a[L[p]],-1);
                ins(Rs[p],1);
            }
            a[L[p]]=Rs[p];
            p--;
        }
        while (r<q[i].r){
            r++;
            ins(a[r],1);
        }
        while (l>q[i].l){
            l--;
            ins(a[l],1);
        }
        while (l<q[i].l){
            ins(a[l],-1);
            l++;
        }
        while (r>q[i].r){
            ins(a[r],-1);
            r--;
        }
        int z=0;
        while (c[z]) z++;
        ans[q[i].id]=z;
    }
    for (int i=1; i<=t1; i++) printf("%d\n",ans[i]);
    return 0;
}