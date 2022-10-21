#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e6 + 50;

int n, a[N];
vi S[N];
string str;
int p[N];
int in_use[N];
priority_queue<pii, vector<pii>, greater<pii> > pque;

void add(int x) {
    if(!S[x].empty()) S[x].pop_back();
}

void del(int x, int idx) {
    S[x].push_back(idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    iota(p, p + N, 0);
    fill(in_use, in_use + N, -1);
    rep(i, 2, N) {
        if(p[i] != i) continue;
        for (int j = 2 * i; j < N; j += i) p[j] = i;
    }
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    cin >> str;
    str = " " + str;
    ll res = 0;
    for (int i = n; i >= 1; i--) {
        while(a[i] > 1) {
            int c = p[a[i]], ct = 0;
            while(a[i] % c == 0) {
                ct++;
                a[i] /= c;
            }
            if(str[i] == '/') {
                while(ct--) del(c, i);
            } else {
                while(ct--) add(c);
            }
            in_use[c] = (S[c].empty() ? -1 : S[c].back());
            if(in_use[c] != -1) pque.push({in_use[c], c});
        }
        while(!pque.empty() && in_use[pque.top().second] != pque.top().first) {
            pque.pop();
        }
        res += (pque.empty() ? n + 1 : pque.top().first) - i;
    }
    cout <<  res << '\n';



}