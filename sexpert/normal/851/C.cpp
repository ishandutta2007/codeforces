#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt {
    array<int, 5> crd;
    pt(array<int, 5> a) : crd(a) {};
    int norm() {
        int res = 0;
        for(int i = 0; i < 5; i++)
            res += crd[i] * crd[i];
        return res;
    }
    pt operator-(const pt& o) {
        array<int, 5> res;
        for(int i = 0; i < 5; i++)
            res[i] = crd[i] - o.crd[i];
        return pt(res);
    }
};

int dot(pt x, pt y) {
    int res = 0;
    for(int i = 0; i < 5; i++)
        res += x.crd[i] * y.crd[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n > 100) {
        cout << "0\n";
        return 0;
    }
    vector<pt> pts;
    for(int i = 0; i < n; i++) {
        array<int, 5> P;
        for(int j = 0; j < 5; j++)
            cin >> P[j];
        pts.push_back(P);
    }
    vector<int> idx;
    for(int i = 0; i < n; i++) {
        bool bad = false;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(i == j || j == k || k == i)
                    continue;
                pt p = pts[j] - pts[i], q = pts[k] - pts[i];
                if(dot(p, q) > 0)
                    bad = true;
            }
        }
        if(!bad)
            idx.push_back(i);
    }
    cout << idx.size() << '\n';
    for(auto i : idx)
        cout << i + 1 << '\n';
}