#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
vector< pair<LL,LL> > ans;
LL x;
int main() {
    cin>>x;
    for(LL n=1;;n++) {
        LL t = n*n*(n+1)/2 - n*(n+1)*(2*n+1)/6;
        LL y = x + t;
        if(n*(n+1)/2>y) break;
        if(y%(n*(n+1)/2) == 0) {
            if(n <= y/(n*(n+1)/2)) {
                ans.push_back(make_pair(n, y/(n*(n+1)/2)));
            } else {
                break;
            }
        }
    }
    if(ans[ans.size()-1].first == ans[ans.size()-1].second) {
        printf("%d\n", 2*ans.size()-1);
        for(auto p: ans)
            printf("%lld %lld\n", p.first, p.second);
        for(int i=(int)ans.size()-2;i>=0;i--)
            printf("%lld %lld\n", ans[i].second, ans[i].first);
    }else{
        printf("%d\n", 2*ans.size());
        for(auto p: ans)
            printf("%lld %lld\n", p.first, p.second);
        for(int i=(int)ans.size()-1;i>=0;i--)
            printf("%lld %lld\n", ans[i].second, ans[i].first);
    }
}
/*
1 * (n-m+1)
2 * (n-m+2)
...
...
m * n

2x + x-1 = A            (3x-1)
3x + 2*(x-1) + x-2 = A  (6x-4)
4x + 3*(x-1) + 2*(x-2) + 3*(x-1) 10x-10

x*(n-x)

n*(n+1)/2*m - (n*n(n+1)/2 - n*(n+1)*(2n+1)/6) = x

m = x/(n*(n+1)/2) + (n - (2n+1)/3)


*/