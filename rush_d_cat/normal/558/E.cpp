#include <iostream>
#include <cstring>
using namespace std;
const int N = 100000+10;
int n,q;
char s[N];

struct Nod {
    int cnt[27];
    void init() {
        memset(cnt,0,sizeof(cnt));
    }
    Nod operator + (const Nod& o) const {
        Nod ans; ans.init();
        for(int i=0;i<26;i++)
            ans.cnt[i] = cnt[i]+o.cnt[i];
        return ans;
    }
} val[N<<2];
int lazy[N<<2];

void push_down(int rt,int l,int r) {
    if (lazy[rt] != -1) {
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        int mid = (l+r)>>1;
        val[rt<<1].init(); 
        val[rt<<1].cnt[lazy[rt]] = mid - l + 1; 
        val[rt<<1|1].init();
        val[rt<<1|1].cnt[lazy[rt]] = r - mid;
        lazy[rt] = -1;
    }
}
void build(int l,int r,int rt) {
    if(l==r) {
        val[rt].init();
        val[rt].cnt[s[l]-'a'] = 1; 
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    val[rt] = val[rt<<1] + val[rt<<1|1];
}

void update(int l,int r,int rt,int L,int R,int x){
    if(L<=l&&r<=R) {
        lazy[rt] = x;
        val[rt].init(); 
        val[rt].cnt[x] = r - l + 1;
        return;
    }
    push_down(rt,l,r);
    int mid = (l+r)>>1;
    if (L<=mid) update(l,mid,rt<<1,L,R,x);
    if (R >mid) update(mid+1,r,rt<<1|1,L,R,x);
    val[rt]=val[rt<<1]+val[rt<<1|1];
}

Nod query(int l,int r,int rt,int L,int R) {
    if (L<=l&&r<=R) {
        return val[rt];
    }
    push_down(rt,l,r);
    int mid=(l+r)>>1;
    if (L<=mid && R<=mid) return query(l,mid,rt<<1,L,R);
    if (L>mid&&R>mid) return query(mid+1,r,rt<<1|1,L,R);
    return query(l,mid,rt<<1,L,R)+query(mid+1,r,rt<<1|1,L,R);
}

int main() {
    scanf("%d%d%s",&n,&q,s+1);

    memset(lazy,-1,sizeof(lazy));
    build(1,n,1);

    for(int i=1;i<=q;i++) {
        int l,r,op;
        scanf("%d%d%d",&l,&r,&op);
        Nod tmp = query(1,n,1,l,r);

        int pos = l;
        if (op == 1) {
            for(int i=0;i<26;i++) {
                if (tmp.cnt[i]) {
                    update(1,n,1,pos,pos+tmp.cnt[i]-1,i);
                    pos += tmp.cnt[i];
                }
            }
        }

        if (op == 0) {
            for(int i=25;i>=0;i--) {
                if (tmp.cnt[i]) {
                    update(1,n,1,pos,pos+tmp.cnt[i]-1,i);
                    pos += tmp.cnt[i];
                }
            }
        }
    }

    for (int i=1;i<=n;i++) {
        Nod tmp = query(1,n,1,i,i);
        for(int j=0;j<26;j++) 
            if (tmp.cnt[j])
                printf("%c", 'a'+j);
    }
    printf("\n");
}