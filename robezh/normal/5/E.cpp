#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e6 + 50, INF = (int)1e9 + 50;
typedef pair<int, int> P;

int n;
int h[N];
int mx = 0, mxcnt = 0;
int cl[N], cr[N];
int nxl[N], nxr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        h[i + n] = h[i + 2 * n] = h[i];
        if(h[i] > mx) {
            mx = h[i];
            mxcnt = 0;
        }
        if(h[i] == mx) mxcnt++;
    }
    stack<P> S;
    S.push({INF, 3 * n});
    for(int i = 3 * n - 1; i >= 0; i--) {
        while(h[i] > S.top().first) S.pop();
        cr[i] = 1;
        if(S.top().first == h[i]) cr[i] += cr[S.top().second];
        while(h[i] == S.top().first) S.pop();
        nxr[i] = S.top().second;
        S.push({h[i], i});
    }
    while(!S.empty()) S.pop();
    S.push({INF, -1});
    for(int i = 0; i < 3 * n; i++) {
        while(h[i] > S.top().first) S.pop();
        cl[i] = 1;
        if(S.top().first == h[i]) cl[i] += cl[S.top().second];
        while(h[i] == S.top().first) S.pop();
        nxl[i] = S.top().second;
        S.push({h[i], i});
    }
    ll res = 1LL * mxcnt * (mxcnt - 1) / 2;
    for(int i = 0; i < n; i++) {
        if(h[i] == mx) continue;
        int cur = i + n;
        int l = nxl[cur], r = nxr[cur];
        if(h[l] == mx && h[r] == mx) res += min(mxcnt, 2);
        else {
            res += 2;
        }
        res += cr[cur] - 1;
    }
    cout << res << endl;

}