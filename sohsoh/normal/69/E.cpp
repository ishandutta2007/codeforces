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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, A[MAXN];

set<ll> st;
map<ll, ll> mp;

int main() {
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> A[i];
        if (mp.find(A[i]) != mp.end()) mp[A[i]]++;
        else if (st.find(A[i]) != st.end()) {
                mp.insert({A[i], 1});
                st.erase(A[i]);
        } else st.insert(A[i]);
    }

    if (st.empty()) cout << "Nothing" << endl;
    else cout << *st.rbegin() << endl;
    for (int i = k; i < n; i++) {
        cin >> A[i];
        ll x = A[i - k];
        if (mp.find(A[i]) != mp.end()) mp[A[i]]++;
        else if (st.find(A[i]) != st.end()) {
                mp.insert({A[i], 1});
                st.erase(A[i]);
        } else st.insert(A[i]);

        if (mp.find(x) != mp.end()) {
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
                st.insert(x);
            }
        } else st.erase(x);


        if (st.empty()) cout << "Nothing" << endl;
        else cout << *st.rbegin() << endl;
    }
    return 0;
}