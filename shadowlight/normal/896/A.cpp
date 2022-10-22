#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll MAXN = 1e5 + 7;
const double EPS = 1e-8;

ll sz1, sz2, sz3, sz4;
string s1, s2, s3, s4;

vector <ll> sz;

char findx(ll n, ll k) {
    if (k >= sz[n]) {
        return '.';
    }
    if (!n) {
        return s1[k];
    }
    if (k < sz2) {
        return s2[k];
    }
    k -= sz2;
    if (k < sz[n - 1]) {
        return findx(n - 1, k);
    }
    k -= sz[n - 1];
    if (k < sz3) {
        return s3[k];
    }
    k -= sz3;
    if (k < sz[n - 1]) {
        return findx(n - 1, k);
    }
    k -= sz[n - 1];
    return s4[k];
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    s1 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    s2 = "What are you doing while sending ";
    s2 += '"';
    s3 = "";
    s3 += '"';
    s3 += "? Are you busy? Will you send ";
    s3 += '"';
    s4 = "";
    s4 += '"';
    s4 += '?';
    sz1 = s1.size();
    sz2 = s2.size();
    sz3 = s3.size();
    sz4 = s4.size();
    sz.resize(MAXN);
    sz[0] = sz1;
    for (int i = 1; i < MAXN; i++) {
        sz[i] = 2 * sz[i - 1] + sz2 + sz3 + sz4;
        if (sz[i] > INF) {
            sz[i] = INF;
        }
    }
    ll q;
    cin >> q;
    for (ll id = 0; id < q; id++) {
        ll n, k;
        cin >> n >> k;
        k--;
        cout << findx(n, k);
    }
}