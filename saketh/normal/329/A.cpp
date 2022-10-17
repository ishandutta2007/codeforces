#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
char grid[128][128];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector <int> cols;

    for (int i = 0; i < N; i++) {
        int k = -1;

        for (int j = 0; j < N; j++) {
            if(grid[i][j] == '.') {
                k = j;
                break;
            }
        }

        if(k != -1) cols.push_back(k);
        else break;

        if(cols.size() == N) {
            for (int i = 0; i < N; i++) {
                cout << i + 1 << " " << cols[i] + 1 << "\n";
            }
            return 0;
        }
    }

    vector <int> rows;

    for (int j = 0; j < N; j++) {
        int k = -1;

        for (int i = 0; i < N; i++) {
            if(grid[i][j] == '.') {
                k = i;
                break;
            }
        }

        if(k != -1) rows.push_back(k);
        else break;

        if(rows.size() == N) {
            for (int i = 0; i < N; i++) {
                cout << rows[i] + 1 << " " << i + 1 << "\n";
            }
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}