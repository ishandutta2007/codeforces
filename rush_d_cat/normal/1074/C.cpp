#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N=600000+10;
const int INF = 1e9+7;
LL min(LL x,LL y) {
    return x<y?x:y;
}
LL max(LL x,LL y){
    return x>y?x:y;
}
vector<int> v;
int id(int x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
LL bitx[N],bity[N]; int n;
void addx(int pos,int x){
    while(pos<N) {
        bitx[pos]=min(bitx[pos],x); pos+=pos&-pos;
    }
}
void addy(int pos,int y){
    while(pos<N) {
        bity[pos]=min(bity[pos],y); pos+=pos&-pos;
    }
}
int queryx(int pos){
    int ans=INF;
    while(pos>0) {
        ans=min(ans,bitx[pos]); pos-=pos&-pos;
    } return ans;
}   
int queryy(int pos){
    int ans=INF;
    while(pos>0){
        ans=min(ans,bity[pos]); pos-=pos&-pos;
    } return ans;
}
struct Nod {
    LL x, y;
    bool operator < (const Nod & o) const {
        if(x==o.x) return y<o.y;
        return x<o.x;
    }
} p[N];

LL solve() {
    for(int i=0;i<N;i++) bitx[i]=bity[i]=INF;
    sort(p+1,p+1+n);
    LL ans = 0;
    for(int i=1;i<=n;i++) {
        int mnx = queryx(id(p[i].y));
        int mny = queryy(id(p[i].y));
        addx(id(p[i].y), p[i].x);
        addy(id(p[i].y), p[i].y);
        if(mnx == INF || mny == INF) continue;
        ans = max(ans, 2*(p[i].x+p[i].y-mnx-mny));
    }
    return ans;
}

LL x[N],y[N];

int main(){
    scanf("%d",&n);
    LL mx_x=-1e9, mn_x = 1e9, mx_y=-1e9, mn_y=1e9;
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
        mx_x = max(mx_x,x[i]);
        mn_x = min(mn_x,x[i]);
        mx_y = max(mx_y,y[i]);
        mn_y = min(mn_y,y[i]);
        p[i].x = x[i], p[i].y = y[i]; v.push_back(y[i]); v.push_back(-y[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
 
    LL ret = solve(); // 00
    //printf("ret = %lld\n", ret); return 0;
    for(int i=1;i<=n;i++) p[i].x = - p[i].x; // 10
    ret = max(ret, solve());
    for(int i=1;i<=n;i++) p[i].y = - p[i].y; // 11
    ret = max(ret, solve()); 
    for(int i=1;i<=n;i++) p[i].x = - p[i].x; // 01
    ret = max(ret, solve());  

    printf("%lld ", ret);
    for(int i=4;i<=n;i++) {
        printf("%lld\n", 2*(mx_x-mn_x)+2*(mx_y-mn_y));
    }
}