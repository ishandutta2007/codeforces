#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int find_index(vector<string> &names, string targ) {
    if (targ == "?") return -1;
    for (int i = 0; i < names.size(); i++)
        if (names[i] == targ) return i;
    assert(false);
}

bool eval(vb &vals, bool vm1, array<int, 3> expr) {
    int v1 = (expr[0] == -1) ? vm1 : vals[expr[0]];
    int v2 = (expr[1] == -1) ? vm1 : vals[expr[1]];

    if (expr[2] == 0) return v1 | v2;
    else if (expr[2] == 1) return v1 & v2;
    else if (expr[2] == 2) return v1 ^ v2;
    else assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vector<string> name(N);
    vb type(N);

    vector<string> value(N); // type 1, just a value
    vector<array<int, 3>> expr(N); // type 2, expression

    for (int i = 0; i < N; i++) {
        cin >> name[i];

        string tmp;
        cin >> tmp >> tmp;

        if (tmp[0] == '0' || tmp[0] == '1') {
            value[i] = tmp;
        } else {
            type[i] = 1;
            expr[i][0] = find_index(name, tmp);

            cin >> tmp;
            if (tmp == "OR") expr[i][2] = 0;
            else if (tmp == "AND") expr[i][2] = 1;
            else if (tmp == "XOR") expr[i][2] = 2;
            else assert(false);

            cin >> tmp;
            expr[i][1] = find_index(name, tmp);
        }
    }

    vb lo(M), hi(M);
    vb val(N);

    for (int b = 0; b < M; b++) {
        array<int, 2> ct = { 0, 0 };

        for (int v = 0; v < 2; v++) {
            for (int i = 0; i < N; i++) {
                if (type[i]) val[i] = eval(val, v, expr[i]);
                else val[i] = value[i][b] - '0';
                ct[v] += val[i];
            }
        }

        if (ct[0] > ct[1]) {
            lo[b] = true;
            hi[b] = false;
        } else if (ct[0] < ct[1]) {
            lo[b] = false;
            hi[b] = true;
        } else {
            lo[b] = false;
            hi[b] = false;
        }
    }

    for (bool b : lo) cout << int(b);
    cout << endl;

    for (bool b : hi) cout << int(b);
    cout << endl;

    return 0;
}