#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n == 1 && m == 1) {
        cout << 0;
        return 0;
    }

    if(n == 1) {
        for(int i = 0; i < m; i++)
            cout << i + 2 << ' ';
        return 0;
    }

    if(m == 1) {
        for(int i = 0; i < n; i++)
            cout << i + 2 << endl;
        return 0;
    }


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << (m + i + 1) * (j + 1) << " \n"[j == m - 1];

}