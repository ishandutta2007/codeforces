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
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*vi colors;

string ask(const vector<pair<int, int>> &qs) {
    stringstream resp;
    for (auto [i, j] : qs) {
        resp << (colors[i] == colors[j] ? '1' : '0');
    }
    return resp.str();
}*/

string ask(const vector<pair<int, int>> &qs) {
    if (qs.size() == 0) { return ""; }

    cout << "Q " << qs.size();
    for (auto [u, v] : qs) {
        cout << " " << u + 1 << " " << v + 1;
    }
    cout << endl;

    string resp;
    cin >> resp;
    if (resp == "-1") {
        assert(false);
    }
    return resp;
}

void solve() {
    vector<pair<int, int>> qs;

    int N;
    cin >> N;

    /*colors.resize(N);
    for (int &v : colors)
        v = rng() % 3;
    WATCHC(colors);*/

    vb eq(N);

    for (int p = 0; p < 2; p++) {
        qs.clear();
        for (int i = p; i + 1 < N; i += 2) {
            qs.emplace_back(i, i + 1);
        }
        string resp = ask(qs);
        for (int i = p, j = 0; i + 1 < N; i += 2) {
            eq[i] = resp[j++] == '1';
        }
    }

    vvi grps;
    for (int i = 0; i < N; ) {
        grps.push_back({ i });
        while (eq[i]) {
            grps.back().push_back(++i);
        }
        i++;
    }

    int G = grps.size();

    vb b2(G);
    for (int of = 0; of <= 2; of += 2) {
        qs.clear();
        for (int g = 2; g + of < G; g += 4) {
            qs.emplace_back(grps[g + of - 2].front(), grps[g + of].front());
            if (g + of + 1 < G)
                qs.emplace_back(grps[g + of - 1].front(), grps[g + of + 1].front());
        }
        string resp = ask(qs);
        for (int g = 2, j = 0; g + of < G; g += 4) {
            b2[g + of] = resp[j++] == '1';
            if (g + of + 1 < G)
                b2[g + of + 1] = resp[j++] == '1';
        }
    }

    vi color(G);
    color[0] = 1;
    if (G > 1) color[1] = 2;
    for (int j = 2; j < G; j++) {
        if (b2[j]) color[j] = color[j-2];
        else color[j] = 3 - color[j-2] - color[j-1];
    }

    array<vi, 3> res;
    for (int i = 0; i < G; i++) {
        for (int v : grps[i])
            res[color[i]].push_back(v);
    }

    cout << "A " << res[0].size() << " " << res[1].size() << " " << res[2].size() << endl;
    for (int c = 0; c < 3; c++) {
        for (int v : res[c])
            cout << v + 1 << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}