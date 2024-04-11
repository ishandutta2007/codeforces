#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    vector <int> xa(n), xb(n);
    for (int i = 0; i < n; i++) {
        cout << "? 0 " << i << endl;
        cin >> xa[i];
        cout << "? " << i << " 0" << endl;
        cin >> xb[i];
    }
    cout << "!" << endl;
    int cnt = 0;
    vector <int> rp;
    for (int i = 0; i < n; i++) {
        vector <int> p(n), b(n);
        p[0] = i;
        bool fl = true;
        for (int j = 0; j < n; j++) {
            b[j] = p[0] ^ xa[j];
            if (b[j] > n) {
                fl = false;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            p[j] = b[0] ^ xb[j];
            if (p[j] > n) {
                fl = false;
                break;
            }
        }
        if (!fl) {
            continue;
        }
        vector <int> cp(n, 0), cb(n, 0);
        for (int j = 0; j < n; j++) {
            cp[p[j]]++;
            if (cp[p[j]] > 1) {
                fl = false;
                break;
            }
            cb[b[j]]++;
            if (cb[b[j]] > 1) {
                fl = false;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (p[b[j]] != j) {
                fl = false;
                break;
            }
        }
        if (fl) {
            cnt++;
            //cout << i << "\n";
            rp = p;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << rp[i] << " ";
    }
    cout << endl;
}