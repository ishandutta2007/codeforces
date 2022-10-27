#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200000+10;
const LL INF = 1e18;
int n,m,k,a,b;
int c[N],state[N];
vector<int> v, vec[4];
int id(int x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
LL sum[N<<2],cnt[N<<2], pre[4][N];
void update(int l,int r,int rt,int pos,int x) {
    if(l==r) {
        sum[rt] += x*v[pos-1]; cnt[rt] += x; return;
    } 
    int mid = (l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos,x);
    else update(mid+1,r,rt<<1|1,pos,x);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1];
}
LL query(int l,int r,int rt,int x) {
    if(x<=0)return 0;
    if(l==r) return min(x,(int)cnt[rt])*v[l-1];
    int mid = (l+r)>>1;
    if (cnt[rt<<1] >= x) return query(l,mid,rt<<1,x);
    return sum[rt<<1] + query(mid+1,r,rt<<1|1,x-cnt[rt<<1]); 
}
bool chaos = 0;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&c[i]); v.push_back(c[i]);
    }
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()), v.end());
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        int x; scanf("%d",&x); state[x] |= 1;
    }
    scanf("%d",&b);
    for(int i=1;i<=b;i++){
        int x; scanf("%d",&x); state[x] |= 2;
    }
    for(int i=1;i<=n;i++) { 
        vec[state[i]].push_back(c[i]);
    }
    for(int i=0;i<4;i++) {
        sort(vec[i].begin(), vec[i].end());
        if(vec[i].size()) {
            pre[i][0]=vec[i][0];
            for(int j=1;j<vec[i].size();j++) pre[i][j]=pre[i][j-1]+vec[i][j];
        }
    }
    for(auto x: vec[0]) update(1,n,1,id(x),1);
    for(auto x: vec[3]) update(1,n,1,id(x),1);

    LL ans = INF;
    int top1 = (int)vec[1].size()-1, top2 = (int)vec[2].size()-1;
    for(int i=0;i<=min((int)vec[3].size(),k);i++) {
        int need = k - i;
        if(i)update(1,n,1,id(vec[3][i-1]),-1);
        if(need > (int)vec[1].size() || need > (int)vec[2].size()) continue;
        //printf("i=%d, need = %d\n",i, need);
        for(int j=top1;j>=max(need,0);j--) update(1,n,1,id(vec[1][j]),1); top1=need-1;
        for(int j=top2;j>=max(need,0);j--) update(1,n,1,id(vec[2][j]),1); top2=need-1;
        LL tmp = (i?pre[3][i-1]:0) + (need?(pre[1][need-1]+pre[2][need-1]):0);
        LL cnt = i + need + need; 
        if (m<cnt) continue;
        tmp += query(1,n,1,m-cnt);
        ans = min(ans, tmp);
    }
    if(ans==INF)ans=-1;
    cout << ans << endl;
}