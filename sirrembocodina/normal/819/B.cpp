#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

int p[1000100];
int cnt[5000100];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long cur = 0;
    int pos = 0;
    forn (i, n) {
        cin >> p[i];
        p[i] -= i + 1;
        cnt[n + p[i]]++;
        cur += abs(p[i]);
        if (p[i] > 0) {
            pos++;
        }
    }
    long long res = cur;
    int ans = 0;
    forn (i, n) {
        if (i == 0) {
            continue;
        }
        
        int last = p[n - i] - i + 1;
        cnt[n + last + i - 1]--;
        cur -= abs(last);
        if (last > 0) {
            --pos;
        }
        
        last += n;
        cnt[n + last + i - 1]++;
        cur += abs(last);
        if (last > 0) {
            ++pos;
        }
        
        cur -= pos;
        cur += n - pos;
        pos -= cnt[n + i];
        
        if (cur < res) {
            res = cur;
            ans = i;
        }
        
//        cerr << cur << endl;
    }
    cout << res << " " << ans << endl;
    return 0;
}