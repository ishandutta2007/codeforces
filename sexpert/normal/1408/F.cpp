#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<array<int, 2>> ops;
vector<int> groups[14];

void dnc(vector<int> &v) {
    int n = v.size();
    if(n == 0)
        return;
    for(int l = 1; l * 2 <= n; l *= 2) {
        for(int gr = 0; gr < n; gr += 2 * l) {
            for(int i = 0; i < l; i++) {
                ops.push_back({v[gr + i], v[gr + l + i]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p2;
    for(int b = 14; b >= 0; b--) {
        if(n & (1 << b))
            p2.push_back(b);
    }

    int pows = __builtin_popcount(n);
    int cur = 1;
    for(auto x : p2) {
        vector<int> wow;
        for(int i = cur; i < cur + (1 << x); i++)
            wow.push_back(i);
        groups[x] = wow;
        cur += (1 << x);
    }
    /*for(auto g : groups) {
        cout << g.size() << '\n';
        for(auto x : g)
            cout << x << " ";
        cout << '\n';
    }*/

    for(int i = 0; i < 14; i++)
        dnc(groups[i]);

    if(pows > 2) {
        int ptr = 1;
        int ta = p2[1], cur = p2[pows - 1];
        //cout << cur << " " << ta << '\n';
        vector<int> gro;
        for(int i = 0; i < (1 << cur); i++)
            gro.push_back(ptr++);
        for(int cur = p2[pows - 1]; cur <= ta; cur++) {
            //for(auto &x : gro)
            //    cout << x << " ";
            //cout << '\n';
            if(groups[cur].size() == 0) {
                for(int i = 0; i < (1 << cur); i++) {
                    ops.push_back({ptr, gro[i]});
                    gro.push_back(ptr++);
                }
            }
            else {
                for(int i = 0; i < (1 << cur); i++) {
                    ops.push_back({gro[i], groups[cur][i]});
                    gro.push_back(groups[cur][i]);
                }
            }
        }
    }

    cout << ops.size() << '\n';
    for(auto &[x, y] : ops)
        cout << x << " " << y << '\n';
}