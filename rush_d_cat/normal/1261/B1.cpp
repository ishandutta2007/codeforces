#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int ans[N];
struct Nod {
    int val, pos;
    bool operator<(const Nod & o) const {
        if (val == o.val) {
            return pos < o.pos;
        } 
        return val > o.val;
    } 
} p[N];

pair< pair<int, int>, int > q[N]; 

int sum[N<<2];
void update(int l, int r, int rt, int pos) {
    if (l==r) {
        sum[rt] ++; return;
    }
    int mid = (l+r)>>1;
    if (pos <= mid) update(l,mid,rt<<1,pos);
    else update(mid+1,r,rt<<1|1,pos);
    sum[rt]=sum[rt<<1] + sum[rt<<1|1];
}
int query(int l,int r,int rt,int k) {
    //printf("que %d %d %d %d\n", l, r, rt, k);
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(sum[rt<<1] >= k) return query(l,mid,rt<<1,k);
    else return query(mid+1,r,rt<<1|1,k-sum[rt<<1]);
}

int n, m, a[N];
int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &p[i].val); p[i].pos=i;
        a[i] = p[i].val;
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        //printf("[%d, %d]\n", p[i].val, p[i].pos);
    }
    scanf("%d", &m);
    for(int i=1;i<=m;i++) {
        scanf("%d%d", &q[i].first.first, &q[i].first.second);
        q[i].second = i;
    }
    sort(q+1,q+1+m);
    for(int i=1,j=1;i<=m;i++) {
        while(j<=n && j<=q[i].first.first) {
            //printf("upd %d\n", p[j].pos);
            update(1,n,1,p[j].pos); 
            j++;
        }
        //printf("que %d\n", q[i].first.second);
        ans[ q[i].second ] = query(1,n,1,q[i].first.second);
    }
    for(int i=1;i<=m;i++) printf("%d\n",a[ans[i]]);
}