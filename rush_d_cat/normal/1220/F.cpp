#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 400000 + 10;
int n,a[N];

namespace ZYH {
    int n,T,stk[N],top;
    struct Tree {
        int lson,rson,val,id;
    } tree[N];
    struct Nod{
        int l,r,rt, d;
    };
    int build() {
         //
        if(n==0) return 0;
        stk[top=1]=1;
        for(int i=2;i<=n;i++){
            while(top>=1 && tree[i].val > tree[stk[top]].val) top--;
            if(top) tree[i].lson=tree[stk[top]].rson, tree[stk[top]].rson=i;
            else tree[i].lson=stk[1];
            stk[++top]=i;
        }
        //BFS
        queue<Nod> q; q.push((Nod){1,n,stk[1],1});
        int mx = 0;
        while(q.size()) {
            Nod now=q.front();q.pop();
            int l=now.l,r=now.r,rt=now.rt;
            //printf("[%d, %d]\n", l,r);
            if(r==l) continue;
            int mid=tree[rt].id;
            if(l<=mid-1) q.push((Nod){l,mid-1,tree[rt].lson, now.d+1});
            if(r>=mid+1) q.push((Nod){mid+1,r,tree[rt].rson, now.d+1});
            mx = max(mx, now.d + 1);
        }
        return mx;
    }
};

int getDep(int l,int r) {
    ZYH::n = r - l + 1;
    for (int i=1;i<=r-l+1;i++) {
        ZYH::tree[i].val = - a[i+l-1];
        ZYH::tree[i].id  = i;
    }
    return ZYH::build();
}

int main() {
    scanf("%d", &n);
    int p1,p2;
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        a[i+n] = a[i];
        if (a[i] == 1) {
            p1 = i; p2 = i + n;
        }
    }

    int lef = 0, rig = n-1;
    while(rig - lef > 1) {
        int mid = (lef + rig) >> 1;
        // [p1-mid,p1-1];
        int vL = getDep(p2-mid, p2-1);
        int vR = getDep(p1+1, p1+n-1-mid);
        if (vL <= vR) {
            lef = mid;
        } else {
            rig = mid;
        }
    }
    /*
    while(1) {
        int x, y; scanf("%d %d", &x, &y);
        printf("%d\n", getDep(x,y));
    }
    */
    //4 1 2 3
    
    
    int ans = N, bst = 0;
    for(int mid = max(lef-2,0); mid <= min(n-1,lef+2); mid++) {
        int vL = getDep(p2-mid, p2-1);
        int vR = getDep(p1+1, p1+n-1-mid);        
        //printf("mid = %d, lef = %d, rig = %d\n", mid, vL, vR);
        if (ans > max(vL, vR) + 1) {
            ans = max(vL, vR) + 1;
            bst = mid;
        }
    }

    printf("%d ", ans);
    int id = bst + 1;
    //printf("id = %d\n", id);
    if (id < p1) {
        printf("%d\n", p1 - id == n ? 0 : p1 - id);
    } else {
        printf("%d\n", p1 + n-id == n ? 0 : p1+n-id);
    }
}
/*
6
6 5 3 1 4 2 6 5 3 1 4 2

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", &tree[i].val);tree[i].id = i;
    }
    build();
}
*/