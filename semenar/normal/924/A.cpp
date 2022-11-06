#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <random>
#include <map>
#include <iomanip>

using namespace std;

int inf = (int)1e9 + 7;

struct fraction {
    int p;
    int q;

    friend bool operator<(fraction a, fraction b);
};

bool operator<(fraction a, fraction b) {
    return (long long)a.p * b.q < (long long)a.q * b.p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> board(n);

    for (int i = 0; i < n; i++) cin >> board[i];

    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++)
            for (int c = 0; c < n; c++)
                for (int d = 0; d < m; d++)
                    if ((board[a][b] == '#') + (board[a][d] == '#') + (board[c][b] == '#') + (board[c][d] == '#') == 3) {
                        cout << "No" << endl;
                        return 0;
                    }

    cout << "Yes" << endl;
    return 0;
}