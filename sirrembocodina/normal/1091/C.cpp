#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[5100];
int d[5100][3100][2];

int main() {
    ios::sync_with_stdio(0);
    long long n;
    cin >> n;    
    set<long long> ans;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i) {
           continue;
        }
//        cerr << i <<  " " << i * (i - 1) / 2 * (n / i) + i << endl;
        ans.insert(i * (i - 1) / 2 * (n / i) + i);
        ans.insert((n / i) * (n / i - 1) / 2 * i + n / i);
    }
    for (auto i = ans.begin(); i != ans.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}