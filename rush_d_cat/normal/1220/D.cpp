#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
int n; LL b[N],a[N];
vector<int> ans;

void solve(vector<int> v) {
    if(v.size() == 0) return;
    vector<int> l,r;
    for(auto x: v) {
        if(b[x]%2 == 0) {
            b[x] /= 2;
            l.push_back(x);
        } else {
            r.push_back(x);
        }
    }
    solve(l);
    if(r.size() >= ans.size()) {
        ans = r;
    }
}
bool vis[N];
int main() {
    scanf("%d", &n);
    vector<int> v; 
    for(int i=1;i<=n;i++) {
        scanf("%lld", &b[i]);   a[i]=b[i];
        v.push_back(i);
    }
    solve(v);
    for(auto x: ans) {
        vis[x] = 1;
    }
    printf("%d\n", n - ans.size());
    for(int i=1;i<=n;i++) {
        if(vis[i] == 0)
            printf("%lld ", a[i]);
    }
}