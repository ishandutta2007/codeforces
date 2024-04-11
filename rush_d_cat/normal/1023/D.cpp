#include <iostream>
using namespace std;
const int N = 300000+10;
int n,q;
int a[N],l[N],r[N],fg[N];
int val[N<<2];
void build(int l,int r,int rt) {
    if(l==r) {
        val[rt] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    val[rt] = min(val[rt<<1], val[rt<<1|1]);
}
int query(int l,int r,int rt,int L,int R) {
    if(L<=l&&r<=R) return val[rt];
    int mid=(l+r)>>1, ans=1e9;
    if (L<=mid) ans=min(ans,query(l,mid,rt<<1,L,R));
    if (R >mid) ans=min(ans,query(mid+1,r,rt<<1|1,L,R));
    return ans;
}

int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); 
    }
    a[0]=1;
    for(int i=1;i<=n;i++) {
        if(a[i]==0) {
            a[i]=a[i-1]; fg[i]=1;
        }
        r[a[i]] = i;
        if(l[a[i]] == 0) {
            l[a[i]] = i;
        }
    }

    build(1,n,1);
    bool ok = 1;
    for(int i=1;i<=q;i++) {
        if(l[i]==0) continue;
        if(query(1,n,1,l[i],r[i]) < i) ok=0;
    }

    bool ok2 = 0;
    for(int i=1;i<=n;i++) {
        if (a[i]==q) {
            ok2 = 1;
        }
    }
    if(ok2 == 0) {
        for(int i=1;i<=n;i++) {
            if(fg[i] == 1) {
                a[i] = q; ok2 = 1; break;
            }
        }
    }  
    if (ok2 == 0) ok = 0;

    if(ok){
        printf("YES\n");
        for(int i=1;i<=n;i++) printf("%d ", a[i]);
    } else {
        printf("NO\n");
    }
}