#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

int main() {
    vector<int> a = {4, 8, 15, 16, 23, 42};

    vector<int> b(4);
    for(int i = 0; i < 4; i++) {
        cout << "? " << i + 1 << ' ' << i + 2 << endl;
        cin >> b[i];
    }



    vector<int> p(6);
    for(int i = 0; i < 6; i++)
        p[i] = i;

    do {
        vector<int> c(6, -1);
        for(int i = 0; i < 6; i++)
            c[i] = a[p[i]];

        bool res = true;
        for(int i = 0; i < 4; i++) {
            if(c[i] * c[i + 1] != b[i])
                res = false;
        }

        if(res) {
            cout << "! ";
            for(auto x : c)
                cout << x << ' ';
            return 0;
        }

    } while(next_permutation(p.begin(), p.end()));
}