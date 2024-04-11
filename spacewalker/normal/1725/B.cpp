#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
typedef long long ll;

int main() {
    int n,k; cin >> n >> k;
    deque<int> v(n);
    rep(i,0,n) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    while (!v.empty()) {
       ll ref = v.back();
       v.pop_back();
       ll curr = 1;
       while (!v.empty() && curr * ref <= k) {
           int u = v.front();
           v.pop_front();
            curr++;
       }
       if (curr * ref > k) ++ans;
    }
    cout << ans << '\n';
}