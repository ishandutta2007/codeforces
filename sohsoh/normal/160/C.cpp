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

ll A[MAXN], n, k;
map<ll, ll> mp;

int main() {
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (mp.find(A[i]) == mp.end()) mp.insert({A[i], 0});
        mp[A[i]]++;
    }

    for (pll e : mp) {
        if (e.Y * n < k) {
            k -= n * e.Y;
            continue;
        }

        for (pll e2 : mp) {
            if (e2.Y * e.Y < k) {
                k -= e2.Y * e.Y;
                continue;
            }

            cout << e.X << sep << e2.X << endl;
            break;
        }

        break;
    }
    return 0;
}