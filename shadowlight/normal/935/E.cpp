#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

string s;

int a = 1, b = 0;

int parse(int l, int &op, vector <int> &mink, vector <int> &maxk) {
    vector <int> minl, minr, maxl, maxr;
    int opl = 0, opr = 0;
    if (s[l] == '(') {
        l = parse(l + 1, opl, minl, maxl);
    } else {
        int d = s[l] - '0';
        minl.push_back(d);
        maxl.push_back(d);
    }
    l += 2;
    if (s[l] == '(') {
        l = parse(l + 1, opr, minr, maxr);
    } else {
        int d = s[l] - '0';
        minr.push_back(d);
        maxr.push_back(d);
    }
    //cout << opl << " " << opr << "\n";
    op = opl + opr + 1;
    mink.resize(op + 1, INF);
    maxk.resize(op + 1, -INF);
    for (int i = 0; i <= opl; i++) {
        for (int j = 0; j <= opr; j++) {
            mink[i + j + a] = min(mink[i + j + 1], minl[i] + minr[j]);
            mink[i + j + b] = min(mink[i + j], minl[i] - maxr[j]);
            maxk[i + j + a] = max(maxk[i + j + 1], maxl[i] + maxr[j]);
            maxk[i + j + b] = max(maxk[i + j], maxl[i] - minr[j]);
        }
    }
    return l + 1;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> s;
    int p, m;
    cin >> p >> m;
//    if (p > m) {
//        swap(a, b);
//        swap(p, m);
//    }
    if (p + m == 0) {
        cout << s[0] << "\n";
        return 0;
    }
    vector <int> mink, maxk;
    int op;
    parse(1, op, mink, maxk);
    cout << maxk[p];

}