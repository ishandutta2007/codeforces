#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;
#define M 100005

int a[M];
struct dat{
    int l,r,t;
    dat(int l=0,int r=0,int t=0):l(l),r(r),t(t){}
};
dat q[M];
int b[M],p[M];
bool operator <(dat a,dat b){
    return a.r<b.r;
}
void add(int *a,int b,int c){
    for(;b<M;b+=b&-b) a[b]+=c;
}
int sum(int *a,int b){
    int res=0;
    for(;b;b-=b&-b) res+=a[b];
    return res;
}
int A[M],B[M],res[M];
int main(){
    //freopen("d.in","r",stdin);
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]=b[a[i]];
        b[a[i]]=i;
    }
    int m;
    scanf("%d",&m);
    int st,en;
    for(i=1;i<=m;i++){
        scanf("%d %d",&st,&en);
        q[i]=dat(st,en,i);
    }
    sort(q+1,q+m+1);
    int j=1;
    memset(b, 0, sizeof(b));
    for(i=1;i<=n;i++){
        add(A,p[i]+1,1); add(A,i+1,-1);
        if(p[p[i]] && i-p[i]!=p[i]-p[p[i]]){ add(B,b[a[i]]+1,1); add(B,p[p[i]]+1,-1);   b[a[i]]=p[p[i]]; }
        while(j<=m && q[j].r<i) j++;
        while(j<=m && q[j].r==i){
            int s1=sum(A,q[j].l);
            int s2=sum(B,q[j].l);
            if(s2==s1) s1++;
            res[q[j].t]=s1;
            j++;
        }
    }
    for(i=1;i<=m;i++) printf("%d\n",res[i]);
}