/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], n;

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    if (*max_element(A, A + n) == *min_element(A, A + n)) {
        cout << 0 << sep << n * (n - 1) / 2 << endl;
        return 0;
    }
    cout << *max_element(A, A + n) - *min_element(A, A + n) << sep << ll(count(A, A + n, *max_element(A, A + n))) * ll(count(A, A + n, *min_element(A, A + n))) << endl;;
    return 0;
}