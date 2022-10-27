#include <iostream>
#include <cstring>
using namespace std;
const int N = 200000+10;
const int B = 29;
typedef long long LL;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int n, q, a[N], b[N], bit[N];
void add(int i, int x) {
    while (i < N) {
        bit[i] ^= x;
        i += i&(-i);
    }
}
int sum(int i) {
    int ret = 0;
    while (i) {
        ret ^= bit[i];
        i -= i&(-i);
    }
    return ret;
}
struct Nod{
    int s[30];
    void init() {
        memset(s,0,sizeof(s));
    }
    void insert(int x){
        for(int i=B;i>=0;i--) if((x>>i)&1){
            if(s[i]==0) {
                s[i]=x;break;
            }else{
                x^=s[i];
            }
        }
    }
    void print() {
        for (int i=0;i<=B;i++) printf("%d ", s[i]);
        printf("\n");
    }
    int count() {
        int ret = 0;
        for (int i=0;i<=B;i++) ret += s[i]?1:0;
        return ret;
    } 
} nod[N*5];
Nod unite(Nod nod1, Nod nod2){
    for (int i=0;i<=B;i++) {
        nod1.insert(nod2.s[i]);
    }
    return nod1;
}
void push_up(int rt) {
    nod[rt] = unite(nod[rt<<1], nod[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        Nod ans; ans.init(); ans.insert(b[l]);
        nod[rt] = ans;
        return;
    }    
    int mid = (l+r)>>1;
    build(lson); 
    build(rson);
    push_up(rt);
}
Nod query(int l, int r, int rt, int L, int R) {
    //printf("que %d %d %d %d\n", l, r, L, R);
    if (L <= l && r <= R) {
        //printf("[%d, %d]\n", l, r);
        //nod[rt].print();
        return nod[rt];    
    }
    int mid = (l + r) >> 1;   
    Nod ans; ans.init();
    if (mid >= L) // [L, mid]
        ans = unite(ans, query(lson, L, R));
    if (mid <  R) // [mid+1, R]
        ans = unite(ans, query(rson, L, R));
    return ans;
}                                                  

void update(int l, int r, int rt, int pos, int d) {
    if (l == r) {
        //printf("upd %d %d\n", pos, d);
        Nod ans; ans.init();
        ans.insert(d^b[l]);
        nod[rt]=ans;
        return;
    }
    int mid=(l+r)>>1;
    if (pos <= mid) 
        update(lson, pos, d);
    else
        update(rson, pos, d);
    push_up(rt);
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) b[i]=a[i]^a[i-1],add(i,b[i]);
    build(1,n,1);
    while(q--){
        int t,l,r,k;
        scanf("%d%d%d",&t,&l,&r); 
        if(t==1){
            scanf("%d",&k); 
            update(1,n,1,l,k); b[l]^=k, add(l, k);
            if (r+1<=n) update(1,n,1,r+1,k), b[r+1]^=k, add(r+1, k);
        }
        if(t==2){   
            Nod tmp;tmp.init();
            if (l<r) tmp = query(1,n,1,l+1,r);
            //for(int i=1;i<=16;i++) nod[i].print();
            //tmp.print();
            tmp.insert(sum(l));
            int c = tmp.count();
            LL ret=(1LL<<c);
            printf("%lld\n",ret);
        }
    }        
}