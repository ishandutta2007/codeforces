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

bool feasible(array<int, 6> &ct, array<int, 64> &fc) {
    for (int m = 0; m < 64; m++) {
        int need = 0;
        for (int i = 0; i < 6; i++)
            if ((m>>i)&1)
                need += ct[i];
        
        int have = 0;
        for (int f = 0; f < 64; f++)
            if (m&f)
                have += fc[f];

        if (need > have) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string str;
    cin >> str;

    int N = str.size();
    vi put(N, 0b111111);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int inx;
        string allow;
        cin >> inx >> allow;
        put[inx-1] = 0;
        for (char c : allow)
            put[inx-1] |= 1 << (c-'a');
    }

    array<int, 6> ct{};
    for (char c : str)
        ct[c-'a']++;

    array<int, 64> fc{};
    for (int v : put)
        fc[v]++;

    if (!feasible(ct, fc)) {
        cout << "Impossible\n";
        return 0;
    }

    char ans[N];
    for (int i = 0; i < N; i++) {
        fc[put[i]]--;
        for (int v = 0; v < 6; v++) {
            if (((put[i]>>v)&1) == 0) continue;
            ct[v]--;
            if (feasible(ct, fc)) {
                ans[i] = 'a' + v;
                break;
            }
            ct[v]++;
        }
    }

    for (char c : ans) cout << c;
    cout << endl;
    return 0;
}