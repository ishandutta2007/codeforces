#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;

const int N = 100000+10;
int n;
LL x[N],y[N];
map<LL,LL> mp;
vector< pair<LL,LL> > v;

int top; pair<double, pair<LL,LL> > stk[N];
double slope(pair<LL,LL> p1, pair<LL,LL> p2) {
    return 1.0 * (p2.second - p1.second) / (p2.first - p1.first);
}


int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]); 
        if(mp.find(x[i]) == mp.end()) mp[x[i]] = y[i];
        else mp[x[i]]=max(mp[x[i]], y[i]);
    }

    for(auto p: mp) {
        v.push_back(make_pair(p.first, p.second));
    }
    for(int i=(int)v.size()-1;i>=0;i--) {
        pair<LL,LL> now = v[i]; now.second -= now.first * now.first;
        //printf("# %lld %lld\n", now.first, now.second);
        //printf("k = (%lld, %lld) %.8f\n", stk[top].second.first,stk[top].second.second, slope(now, stk[top].second));
        while(top && slope(now, stk[top].second) < stk[top].first - 1e-9) -- top;
        if(top) stk[top+1] = make_pair(slope(now, stk[top].second), now); 
        else stk[top+1] = make_pair(-1e18, now);
        ++ top;
        //printf("top = %d\n", top);
    }
    //printf("top = %d\n", top);

    LL ans = 0;
    for(int i=2,j=2;i<=top;i=j){
        //printf("(%lld %lld) %.5f\n", stk[i].second.first, stk[i].second.second, stk[i].first);
        while(j<=top && stk[j].first - stk[i].first < 1e-9) j ++;
        //printf("[%d,%d)\n", i,j);
        ans ++;
    }
    cout << ans << endl;
}