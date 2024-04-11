#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n > a * b) {
        cout << -1;
        return 0;
    }
    int black = 1, white = 2;
    vector <vector <int> > data(a, vector <int> (b, 0));
    for (int i = 0; i < b; i++) {
        for (int j = 0; j <= min(a - 1, i); j++) {
            if (i % 2 == 0) {
                if (black > n) break;
                data[j][i - j] = black;
                black += 2;
            } else {
                if (white > n) break;
                data[j][i - j] = white;
                white += 2;
            }
        }
    }
    for (int i = 1; i < a; i++) {
        for (int j = 0; j <= min(a - i - 1, b - 1); j++) {
            if ((b + i - 1) % 2 == 0) {
                if (black > n) break;
                data[i + j][b - j - 1] = black;
                black += 2;
            } else {
                if (white > n) break;
                data[i + j][b - j - 1] = white;
                white += 2;
            }
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}