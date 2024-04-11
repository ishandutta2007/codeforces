#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

ll a[100100];
ll b[100100];
ll sa[100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    long long n, s;
    cin >> n >> s;
    if (s < 2 * n - 1 || s > n * (n + 1) / 2) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    ll l = 0, r = n - 1;
    while (l < r - 1) {
        ll m = (l + r) / 2;
        ll sum = 0;
        ll left = n;
        ll cp = 1;
        int i = 1;
        while (left > 0) {
            sum += min(left, cp) * i;
            if (sum > s) {
                break;
            }
            left -= cp;
            cp *= m;
            ++i;
        }
        if (sum > s) {
            l = m;
        } else {
            r = m;
        }
    }
    l = r;
//    cerr << l << endl;
    s -= n;
    a[0] = b[0] = 1;
    ll left = n - 1;
    int i = 1;
    ll cur = 0;
    ll cp = l;
    while (left > 0) {
        cur += i * min(left, cp);
        b[i] = min(left, cp);
        left -= cp;
        cp *= l;
        ++i;
    }
    --i;
    int j = 1;
    forn (asdf, n - 1) {
/*        forn (q, n) {
            cerr << a[q] << " " << b[q] << endl;
        }
        cerr << endl;*/
        while (i && b[i] == a[i]) {
            --i;
        }
//        cerr << i << " " << j << endl << endl;
        while (j) {
            if (a[j] == a[j - 1] * l) {
                --j;
                continue;
            }
            if (b[j] > a[j]) {
                break;
            }
            if (cur + j - i <= s) {
                break;
            }
            --j;
        }
        if (b[j] > a[j]) {
            ++a[j];
            ++j;
            continue;
        }
        ++a[j];
        --b[i];
        cur += j - i;
        ++j;
    }
/*    cerr << "!!!!" << endl;
        forn (q, n) {
            cerr << a[q] << " " << b[q] << endl;
        }
        cerr << endl;*/
//    cerr << cur << endl;
    
    forn (i, n) {
        sa[i + 1] = sa[i] + a[i];
    }
    forn (i, n) {
        if (!i) {
            continue;
        }
        if (!a[i]) {
            break;
        }
        forn (j, a[i]) {
            cout << sa[i - 1] + 1 + j / l << " ";
        }
    }
    return 0;
}