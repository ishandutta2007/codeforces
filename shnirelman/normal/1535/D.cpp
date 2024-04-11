#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

vector<int*> ptr;
vector<int> val;

void upd(int* p, int x) {
    val.push_back(*p);
    ptr.push_back(p);
    *p = x;
}

void rollback() {
   *ptr.back() = val.back();
   ptr.pop_back();
   val.pop_back();
}

/*
3
0110?11
6
1 ?

*/

int main() {
    int k;
    cin >> k;

    int n = (1 << k);

    string s;
    cin >> s;

    vector<vector<char>> a(k);
    vector<pii> b;
    for(int i = 0; i < k; i++) {
        a[i].resize(1 << (k - i - 1));
//        cout << i << ' ' << a[i].size() << endl;
        for(int j = 0; j < a[i].size(); j++) {
            a[i][j] = s[b.size()];
            b.emplace_back(i, j);
        }
    }
//    for(auto p : b)
//        cout << p.f << ' ' << p.s << endl;
//return 0;
    vector<vector<int>> f(k + 1);
    for(int i = 0; i < k + 1; i++) {
        f[i].resize(1 << (k - i));
    }
    for(int i = 0; i < n; i++) {
        f[0][i] = 1;
    }
//return 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == '?') {
                f[i + 1][j] = f[i][j * 2] + f[i][j * 2 + 1];
            } else if(a[i][j] == '0') {
                f[i + 1][j] = f[i][j * 2];
            } else {
                f[i + 1][j] = f[i][j * 2 + 1];
            }
        }
    }

    int q;
    cin >> q;

    for(int ind = 0; ind < q; ind++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;

        int i1 = b[pos].f, j1 = b[pos].s;



        int i = i1, j = j1;
        a[i][j] = c;
//        cout << i << ' ' << j << ' ' << pos << ' ' << b.size() << endl;
//        if(c == '?') {
//            upd(&f[i + 1][j], f[i][j * 2] + f[i][j * 2 + 1]);
//        } else if(c == '0') {
//            upd(&f[i + 1][j], f[i][j * 2]);
//        } else {
//            upd(&f[i + 1][j], f[i][j * 2 + 1]);
//        }



        while(i < k) {

            if(a[i][j] == '?') {
                upd(&f[i + 1][j], f[i][j * 2] + f[i][j * 2 + 1]);
            } else if(a[i][j] == '0') {
                upd(&f[i + 1][j], f[i][j * 2]);
            } else {
                upd(&f[i + 1][j], f[i][j * 2 + 1]);
            }
            i++;
            j /= 2;
        }

//        for(int i = 0; i <= k; i++) {
//            for(int j = 0; j < f[i].size(); j++)
//                cout << f[i][j] << ' ';
//            cout << endl;
//        }


        cout << f[k][0] << endl;

//        while(!val.empty())
//            rollback();
    }

//    for(int i = 0; i <= k; i++) {
//        for(int j = 0; j < f[i].size(); j++)
//            cout << f[i][j] << ' ';
//        cout << endl;
//    }
//
//    cout << f[k][0] << endl;
}