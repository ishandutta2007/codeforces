#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        int ret = INT_MAX;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                for (int k=0; k<3; k++) {
                    int v[3];
                    v[0] = a + dx[i];
                    v[1] = b + dx[j];
                    v[2] = c + dx[k];
                    sort(v, v + 3);
                    ret = min(ret, v[2] - v[0]);
                }

        cout << 2 * ret << "\n";
    }

    return 0;
}