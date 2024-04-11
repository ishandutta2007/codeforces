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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll A[3] = { count(all(s), 'R'), count(all(s), 'P'), count(all(s), 'S') };
        ll ind = max_element(A, A + 3) - A;
        if (ind == 0) for (int i = 0; i < s.size(); i++) cout << 'P';
        else if (ind == 1) for (int i = 0; i < s.size(); i++) cout << 'S';
        else for (int i = 0; i < s.size(); i++) cout << 'R';
        cout << endl;
    }
    return 0;
}