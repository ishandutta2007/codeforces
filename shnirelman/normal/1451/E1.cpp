#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const int LG = 16;

vector<int> A = {0, 0, 2, 3};

//int get(int t, int i, int j) {
//    if(t == 0)
//        return A[i] & A[j];
//    else if(t == 1)
//        return A[i] | A[j];
//    else
//        return A[i] ^ A[j];
//}

int get(int t, int i, int j) {
    string s = (t == 0 ? "AND" : (t == 1 ? "OR" : "XOR"));
    cout << s << ' ' << i + 1 << ' ' << j + 1 << endl;

    int x;
    cin >> x;

    return x;
}

int geti(int x, int i) {
    return (x >> i) & 1;
}

void seti(int& x, int i) {
    x |= (1 << i);
}

int main() {
    int n;
    cin >> n;

    int xab = get(2, 0, 1), xac = get(2, 0, 2);
    int xbc = xab ^ xac;

    int aab = get(0, 0, 1), aac = get(0, 0, 2);
    int abc = get(0, 1, 2);

    vector<int> a(n, 0);
    for(int i = 0; i < LG; i++) {
        vector<int> b = {geti(aab, i), geti(aac, i), geti(abc, i),
                        geti(xab, i), geti(xac, i), geti(xbc, i)};

        if(b[3] == 0 && b[4] == 0) {
            if(b[0] == 0) {

            } else {
                seti(a[0], i);
                seti(a[1], i);
                seti(a[2], i);
            }
        } else if(b[3] == 0) {
            if(b[0] == 0) {
                seti(a[2], i);
            } else {
                seti(a[0], i);
                seti(a[1], i);
            }
        } else if(b[4] == 0) {
            if(b[1] == 0) {
                seti(a[1], i);
            } else {
                seti(a[0], i);
                seti(a[2], i);
            }
        } else {
            if(b[2] == 0) {
                seti(a[0], i);
            } else {
                seti(a[1], i);
                seti(a[2], i);
            }
        }
    }

    for(int i = 3; i < n; i++) {
        a[i] = a[0] ^ get(2, 0, i);
    }

    cout << "! ";
    for(auto x : a)
        cout << x << ' ';
    cout << endl;
}