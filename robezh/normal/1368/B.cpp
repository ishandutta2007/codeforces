#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

priority_queue<ll, vector<ll>, greater<ll> > pque;

ll prod = 1;
string str = "codeforces";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin >> k;
    for(int i = 0; i < 10; i++) {
        pque.push(1);
    }
    while(prod < k) {
        ll x = pque.top(); pque.pop();
        prod /= x;
        x++;
        pque.push(x);
        prod *= x;
    }
    for(int i = 0; i < 10; i++) {
        ll x = pque.top(); pque.pop();
        while(x--) cout << str[i];
    }
    cout << '\n';
}