#include <bits/stdc++.h>
using namespace std;
const int N = 600;

vector<string> res;

string blank , p , s;


int main() {
    for (int i = 0 ; i < N ; ++ i) {
        blank += '.';
    }
    p = blank;
    p[N / 2] = 'X';

    cin >> s;
    int cur = 0;
    for (auto c : s) {
        res.emplace_back(blank);
        string w = blank; int j = 1;
        while (cur != (c + 1) % 256) {
            w[j] = 'X';
            j += 2;
            cur += 255;
            cur &= 255;
        }
        res.emplace_back(w);
        res.emplace_back(blank);
        res.emplace_back(p);
        res.emplace_back(p);
        res.emplace_back(blank);

        cur += 255;
        cur &= 255;
    }

    for (auto &t : res) {
        cout << t << endl;
    }

}