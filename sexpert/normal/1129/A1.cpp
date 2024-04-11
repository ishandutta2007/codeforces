#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5005;
vector<ll> candies[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        if(b < a)
            b += n;
        candies[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
        sort(candies[i].begin(), candies[i].end());

    for(int st = 1; st <= n; st++) {
        int ans = 0, del = 0;
        for(int i = 0; i < n; i++) {
            int cur = st + i;
            if(cur > n)
                cur -= n;
            if(candies[cur].empty()) {
                del++;
                continue;
            }
            int cst = del + (n*(candies[cur].size() - 1) + candies[cur][0] - cur);
            ans = max(ans, cst);
            del++;
        }
        cout << ans << " ";
    }
    cout << endl;
}