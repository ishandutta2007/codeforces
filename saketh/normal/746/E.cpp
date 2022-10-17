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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi vals(N);
    vb exch(N);
    unordered_set<int> seen;

    int even = 0, odd = 0;
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        if (seen.count(vals[i]))
            exch[i] = true;
        else {
            seen.insert(vals[i]);
            if (vals[i]&1) odd++;
            else even++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (exch[i]) continue;
        if (vals[i]&1)
            exch[i] = odd > N/2;
        else
            exch[i] = even > N/2;
        if (exch[i]) {
            if (vals[i]&1) odd--;
            else even--;
        }
    }

    int no = 1, ne = 2;
    for (int i = 0; i < N; i++) {
        if (!exch[i]) continue;
        if (odd < N/2) {
            while (seen.count(no)) no += 2;
            if (no > M) { cout << -1 << endl; exit(0); }
            vals[i] = no;
            seen.insert(no);
            odd++;
        } else {
            while (seen.count(ne)) ne += 2;
            if (ne > M) { cout << -1 << endl; exit(0); }
            vals[i] = ne;
            seen.insert(ne);
            even++;
        }
    }

    int used = 0;
    for (bool b : exch)
        used += b;

    cout << used << endl;
    for (int i = 0; i < N; i++)
        cout << vals[i] << " ";
    cout << endl;

    return 0;
}