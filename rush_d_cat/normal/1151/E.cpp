#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,a[N],cnt[N];
int L[N],R[N];
int stk[N],top;
int mx[N<<2];
void build(int l,int r,int rt) {
    if(l==r) {
        mx[rt]=a[l]; return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1); 
    build(mid+1,r,rt<<1|1);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return mx[rt];
    int mid=(l+r)>>1,ans=0;
    if(L<=mid)ans=max(ans,query(l,mid,rt<<1,L,R));
    if(R >mid)ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
    return ans;
}
int cac(int l,int r) {
    bool ok[102]={0}; int ans=0;
    for(int i=1;i<=n;i++){
        ok[i]=a[i]<=r&&a[i]>=l;
        if(ok[i]==1 && ok[i-1]==0) ans++;
    }
    for(int i=1;i<=n;i++){
        if(ok[i]){
            int j=i;
            while(ok[j]) j++;
            int mn=N,pos;
            for(int x=i;x<j;x++){
                if(a[x]<mn){
                    mn=a[x],pos=x;
                }
            }
            cnt[pos]++;
            if(pos==3){
                printf("[%d,%d]\n", l,r);
            }
            i=j-1;
        }
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    } 
    build(1,n,1);

    top=0;
    for(int i=1;i<=n;i++){
        while(top && a[stk[top]]>a[i]) --top;
        L[i]=stk[top];
        stk[++top]=i;
    }

    top=0;stk[0]=n+1;
    for(int i=n;i>=1;i--){
        while(top && a[stk[top]]>=a[i]) --top;
        R[i]=stk[top];
        stk[++top]=i;
    }
    //printf("# %d\n", query(1,n,1,2,3));
    LL ans=0;
    for(int i=1;i<=n;i++){
        int A=a[i]-a[L[i]], mx1=query(1,n,1,L[i]+1,i); 
        int B=a[i]-a[R[i]], mx2=query(1,n,1,i,R[i]-1);
        LL tmp=0;
        tmp=tmp+1LL*min(A,B)*(n-a[i]+1);
        //if(i==3)printf("%lld\n", tmp);
        tmp=tmp+1LL*max(min(mx1,mx2)-a[i],0)*max(a[L[i]],a[R[i]]); // [a[i],min(mx1,mx2)
        //if(i==3)printf("mx1=%d,mx2=%d,a=%d,L=%d,R=%d\n", mx1,mx2,a[i],L[i],R[i]);
        // [min(mx1,mx2), max(mx1,mx2))
        if(mx1<mx2) {
            tmp=tmp+1LL*(mx2-mx1)*max(a[R[i]]-a[L[i]],0);
        } else {
            tmp=tmp+1LL*(mx1-mx2)*max(a[L[i]]-a[R[i]],0);
        }
        //if(i==3)printf("tmp=%lld\n", tmp);
        ans+=tmp;
    }
    /*
    LL tmp=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++)tmp+=cac(i,j);
    }
    for(int i=1;i<=n;i++){
        printf("cnt[%d]=%d\n", i,cnt[i]);
    }
    */
    //cout<<tmp<<endl;
    cout<<ans<<endl;
}