#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lex(vector<ll> &v1, vector<ll> &v2) {
    int n = min(v1.size(), v2.size());
    for(int i = 0; i < n; i++) {
        if(v1[i] > v2[i])
            return 1;
        if(v2[i] > v1[i])
            return -1;
    }
    if(v1.size() > v2.size())
        return 1;
    if(v1.size() < v2.size())
        return -1;
    return 0;
}

int main() {
    bool final;
    int n;
    cin >> n;
    vector<ll> v1, v2;
    ll s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if(x > 0) {
            v1.push_back(x);
            s1 += x;
        }
        else {
            v2.push_back(-x);
            s2 -= x;
        }
        if(i == n - 1) {
            if(x > 0)
                final = true;
            else
                final = false;
        }
    }
    if(s1 > s2) {
        cout << "first\n";
        return 0;
    }
    if(s1 < s2) {
        cout << "second\n";
        return 0;
    }
    int l = lex(v1, v2);
    if(l == 1) {
        cout << "first\n";
        return 0;
    }
    if(l == -1) {
        cout << "second\n";
        return 0;
    }
    cout << (final ? "first\n" : "second\n");
}