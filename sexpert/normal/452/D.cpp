#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 5e6 + 10;
int cnt[MAX][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n1, n2, n3, t1, t2, t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;

    int T = t1 + t2 + t3;
    deque<int> tim[3];
    for(int i = 0; i < n1; i++)
        tim[0].push_back(t1 + t2 + t3);
    for(int i = 0; i < n2; i++)
        tim[1].push_back(t1 + t2 + t3);
    for(int i = 0; i < n3; i++)
        tim[2].push_back(t1 + t2 + t3);
    
    int ans = 0;
    for(int i = 0; i < k; i++) {
        int use = max({tim[0][0], tim[1][0], tim[2][0]});
        tim[0].pop_front();
        tim[1].pop_front();
        tim[2].pop_front();
        int st = use - t1 - t2 - t3;
        int T = t1 + t2 + t3;
        tim[0].push_back(st + t1 + t1 + t2 + t3);
        tim[1].push_back(st + t1 + t2 + t2 + t3);
        tim[2].push_back(use + t3);
        //cout << use << endl;
        ans = max(ans, use);
    }
    cout << ans << '\n';
}