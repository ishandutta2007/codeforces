#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a;
    while(n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }

    reverse(a.begin(), a.end());
    int ans = -1;
    for(int mask = 1; mask < (1 << int(a.size())); mask++) {
        int fir = -1, x = 0, cnt = 0;
        for(int i = 0; i < a.size(); i++)
            if(mask & (1 << i)) {
                x = x * 10 + a[i];
                cnt++;
                if(fir == -1)
                    fir = a[i];
            }
        int d = int(sqrt(x));
        for(int i = d - 5; i < d + 5; i++)
            if(i * 1ll * i == x && fir > 0 && cnt > ans)
                ans = cnt;
    }

    cout << (ans == -1 ? -1 : int(a.size()) - ans) << endl;
}