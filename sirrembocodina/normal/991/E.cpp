#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

bool asdf = false;
long long c[20][20];
long long ans = 0;
int cnt[10];
int x[10];

void rec(int i = 0) {
    if (i == 10) {
        long long cur = 1;
        int sum = 0;
        forn (j, 10) {
            sum += x[j];
//            cerr << x[j] << " ";
        }
        forn (j, 10) {
            cur *= c[sum][x[j]];
            sum -= x[j];
        }
        ans += cur;
        return;
    }
    if (cnt[i] == 0) {
        x[i] = 0;
        rec(i + 1);
    } else {
        if (i == 0 && asdf) {   
            x[i] = 0;
            rec(i + 1);
        }
        forn (j, cnt[i]) {
            x[i] = j + 1;
            rec(i + 1);
        }
    }
}

int main() {
    c[0][0] = 1;
    forn (i, 20) {
        if (!i) {
            continue;
        }
        c[i][0] = c[i][i] = 1;
        forn (j, i - 1) {
            c[i][j + 1] = c[i - 1][j] + c[i - 1][j + 1];
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    while (n) {
        cnt[n % 10]++;
        n /= 10;
    }
    rec();
    if (cnt[0]) {
        cnt[0]--;
        long long tmp = ans;
        ans = 0;
        asdf = true;
        rec();
//        cerr << ans << endl;
        ans = tmp - ans;
    }
    cout << ans << endl;
}