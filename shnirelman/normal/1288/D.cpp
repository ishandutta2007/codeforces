#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> a;

vector<int> b;
int x, y;

bool is(int mid) {
    for(int i = 0; i < b.size(); i++)
        b[i] = -1;

    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = 0; j < m; j++)
            if(a[i][j] >= mid)
                cur |= (1 << j);

        b[cur] = i;
    }

    for(int i = 0; i < b.size(); i++)
        if(b[i] != -1)
            for(int j = 0; j < b.size(); j++)
                if(b[j] != -1 && (i | j) == (1 << m) - 1) {
                    x = b[i], y = b[j];
                    return true;
                }

    return false;

}

int main() {
    cin >> n >> m;

    a.resize(n, vector<int> (m));
    b.resize(1 << m, -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int l = 0,  r = 1e9 + 13;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        if(is(mid))
            l = mid;
        else
            r = mid;
    }

    is(l);
    cout << x + 1 << ' ' << y + 1 << endl;
}