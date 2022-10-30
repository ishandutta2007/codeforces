
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    string s;
    cin >> s;
    vll v(26);
    for (char c : s) ++v[c - 'a'];
    ll best = 0;
    for (ll x : v) best = max(best, x);
    for (char c = 'a'; c <= 'z'; ++c){
        vll occs(26), sums(26);
        for (char c2 : s){
            if (c == c2){
                for (ll i = 0; i < 26; ++i) sums[i] += occs[i];
            }
            ++occs[c2 - 'a'];
        }
        for (ll x : sums) best = max(best, x);
    }
    cout << best << endl;
    return 0;
}