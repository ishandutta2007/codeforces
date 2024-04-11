#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    auto adj = [](pair<int, int> a, pair<int, int> b) {
        return a.first == b.first || a.second == b.second;
    };

    auto verify = [&](vector<pair<int, int>>& seq, vb& rem) {
        assert(!rem[0]);
        int lfix = 0;
        for (int i = 1; i < seq.size(); i++) {
            if (!adj(seq[i], seq[i-1]))
                cout << "Put " << seq[i].first << " " << seq[i].second << " next to " << seq[i-1].first << " " << seq[i-1].second << endl;
            if (!adj(seq[i], seq[lfix]))
                cout << "Put " << seq[i].first << " " << seq[i].second << " next to " << seq[lfix].first << " " << seq[lfix].second << endl;
            if (!rem[i]) lfix = i;
        }
    };

    vector<pair<int, int>> seq63;
    vb rem63;
    for (int r = 0; r < 6; r++) {
        seq63.emplace_back(r, r);
        rem63.push_back(false);
        for (int c = 0; c < 8; c++) {
            if (c == r || c == r + 1) continue;
            seq63.emplace_back(r, c);
            rem63.push_back(true);
        }
        seq63.emplace_back(r, r+1);
        rem63.push_back(false);
    }
    seq63.emplace_back(6, 6);
    rem63.push_back(false);
    for (int c = 7; c >= 0; c--) {
        if (c == 6) continue;
        seq63.emplace_back(6, c);
        rem63.push_back(c > 0);
    }
    for (int c = 0; c < 8; c++) {
        seq63.emplace_back(7, c);
        rem63.push_back(c > 0 && c < 7);
    }
    verify(seq63, rem63);

    int min63 = 0;
    for (bool b : rem63)
        min63 += !b;

    vector<pair<int, int>> seq15;
    vb rem15;
    seq15.emplace_back(0, 0);
    rem15.push_back(false);
    for (int c = 1; c < 7; c++) {
        seq15.emplace_back(0, c);
        rem15.push_back(true);
    }
    seq15.emplace_back(0, 7);
    rem15.push_back(false);
    for (int r = 1; r < 7; r++) {
        seq15.emplace_back(r, 7);
        rem15.push_back(true);
    }
    seq15.emplace_back(7, 7);
    rem15.push_back(false);
    verify(seq15, rem15);

    int min15 = 0;
    for (bool b : rem15)
        min15 += !b;

    int N;
    cin >> N;
    N++;

    auto& seq = N < min63 ? seq15 : seq63;
    auto& rem = N < min63 ? rem15 : rem63;
    int skip = seq.size() - N;

    for (int i = 0; i < seq.size(); i++) {
        if (rem[i] && skip) skip--;
        else {
            cout << char('a' + seq[i].second) << seq[i].first + 1 << " ";
        }
    }
    cout << endl;

    assert(skip == 0);

    return 0;
}