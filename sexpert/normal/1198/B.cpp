#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 5;
int balance[MAXN], last[MAXN], best[MAXN], payoff[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> balance[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            int y;
            cin >> y;
            balance[x] = y;
            last[x] = i;
        }
        else
            payoff[i] = x;
    }
    for(int i = q - 1; i >= 0; i--)
        best[i] = max(best[i + 1], payoff[i]);
    //for(int i = 0; i < q; i++)
    //    cout << best[i] << " ";
    //cout << endl;
    for(int i = 1; i <= n; i++)
        cout << max(balance[i], best[last[i]]) << " ";
    cout << '\n';
}