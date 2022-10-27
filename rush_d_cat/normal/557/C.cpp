#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N=200000 + 10;
int n,c[202];
bool cmp(int x,int y){
    return x>y;
}

struct Item {
    int l,d;
    bool operator <(const Item&o)const{
        return l<o.l;
    }
} it[N];
LL sum[N];
vector<int> cnt[N]; LL scnt[N];

int main(){
    scanf("%d",&n);
    LL sigma = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&it[i].l); 
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&it[i].d); sigma += it[i].d;
        cnt[it[i].l].push_back(it[i].d); scnt[it[i].l] += it[i].d;
    }

    LL ans=0;
    for(int i=1;i<N;i++){
        if(cnt[i].size() == 0) continue;
        LL tmp = scnt[i];
        LL mx = cnt[i].size(),has=0;

        for(int j=200;j>=1;j--){
            if(has+c[j] < mx) {
                has += c[j], tmp += c[j]*j;
            } else {
                tmp += (mx-has-1)*j;
                has += (mx-has-1);
            }
        }

        ans=max(ans,tmp);
        for(auto x: cnt[i]) {
            c[x] ++;
        }
    }
    ans = sigma - ans;
    printf("%lld\n", ans);
}