#include <bits/stdc++.h>
using namespace std;

struct {
    int digit, i, j;
} pred[100001][3][7];

bool visited[100001][3][7] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    if (n == 1 || n == 2) {
        cout << "-1\n";
        return 0;
    }

    vector<int> tens(n);
    tens[n-1] = 1;
    for (int i=n-2; i>=0; i--)
        tens[i] = tens[i+1] * 10 % 7;

    bool ok = false;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    visited[0][0][0] = true;
    while (!q.empty()) {
        int len, mod3, mod7;
        tie(len, mod3, mod7) = q.front();
        q.pop();

        if (len == n) {
            if (mod3 == 0 && mod7 == 0) {
                ok = true;
                break;
            }
        } else if (len == n - 1) {
            if (!visited[len+1][mod3][mod7]) {
                pred[len+1][mod3][mod7] = {0, mod3, mod7};
                visited[len+1][mod3][mod7] = true;
                q.push(make_tuple(len+1, mod3, mod7));
            }
        } else {
            for (int i=(len == 0); i<10; i++)
                if (!visited[len+1][(mod3+i)%3][(mod7+i*tens[len])%7]) {
                    pred[len+1][(mod3+i)%3][(mod7+i*tens[len])%7] = {i, mod3, mod7};
                    visited[len+1][(mod3+i)%3][(mod7+i*tens[len])%7] = true;
                    q.push(make_tuple(len+1, (mod3+i)%3, (mod7+i*tens[len])%7));
                }
        }
    }

    if (!ok)
        cout << "-1\n";
    else {
        int len = n, i = 0, j = 0;
        stack<int> s;
        while (len > 0) {
            auto nxt = pred[len][i][j];
            s.push(nxt.digit);
            len--;
            i = nxt.i;
            j = nxt.j;
        }

        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << "\n";
    }

    return 0;
}