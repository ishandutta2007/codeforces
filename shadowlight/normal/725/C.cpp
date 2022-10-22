#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector <int> pos(26, -1);
    int a, b, c;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'A';
        if (pos[x] != -1) {
            a = pos[x];
            c = i - pos[x] - 1;
            b = i;
            break;
        }
        pos[x] = i;
    }
    //cout << a << " " << b << " " << c << endl;
    if (c == 0) {
        cout << "Impossible";
        return 0;
    }
    int k = c / 2;
    vector <vector <char> > data(2, vector <char> (13, '#'));
    data[0][12 - k] = s[b];
    int now = 12 - k - 1, x = 0;
    int a1 = a;
    a--;
    while (a >= 0) {
        if (now == -1) {
            x = 1;
            now = 0;
        }
        data[x][now] = s[a];
        if (x) now++; else now--;
        a--;
    }
    a = a1 + 1;
    x = 0;
    now = 12 - k + 1;
    while (a != s.size()) {
        if (a == b) {
            a++;
            continue;
        }
        if (now == 13) {
            x = 1;
            now = 12;
        }
        if (now == -1) {
            x = 0;
            now = 0;
        }
        data[x][now] = s[a];
        if (x) now--; else now++;
        a++;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 13; j++) {
            cout << data[i][j];
        }
        cout << endl;
    }
}
/*
ABCDEFGHIJKLMNOPQRSTUVWXYZ

ABACDEFGHIJKLMNOPQRSTUVWXYZ
*/