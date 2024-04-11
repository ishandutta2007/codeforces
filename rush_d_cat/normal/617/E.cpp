#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d%d",&x,&y)
#define rd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)

const int N=2000000+10;
const double EPS = 1e-8;
int n,m,k,a[N],mp[N],blk;
LL ret=0,ans[N];
struct Item {
    int l,r,id;
    Item(){}
    Item(int l_,int r_) {l=l_,r=r_;}
    bool operator < (const Item & o) const {
        if((l/blk)==(o.l/blk)) return r < o.r;
        return l/blk < o.l/blk;
    } 
} it[N];

void add(int pos) {
    ret += mp[a[pos]^k];
    mp[a[pos]] ++;
}
void del(int pos) {    
    mp[a[pos]] --;
    ret -= mp[a[pos]^k];
}
int main(){
    rd3(n,m,k); blk = sqrt(n);
    rep(i,1,n) rd(a[i]),a[i]=a[i-1]^a[i];
    rep(i,1,m) rd2(it[i].l,it[i].r), it[i].id=i;
    sort(it+1,it+1+m);
    int L = 0, R = 0; mp[0] = 1;
    rep(i,1,m) {
        while (R < it[i].r) {
            R ++; add(R);
        }
        while (R > it[i].r) {
            del(R); R--;
        }     
        while (L < it[i].l-1) {
            del(L); L ++;
        }
        while (L > it[i].l-1) {
            L --; add(L); 
        }
        ans[it[i].id] = ret;
    }
    rep(i,1,m) printf("%lld\n", ans[i]);
}