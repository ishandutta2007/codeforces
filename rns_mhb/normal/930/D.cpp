#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 100010

long long solve(vector <pii> &v) {
    int n = v.size();
    for(int i = 0; i < n; i ++) v[i].first += N, v[i].second += N;
    vector <int> mx(N<<1, 0), mn(N<<1, N<<2);
    vector <int> ux(N<<1, 0), un(N<<1, N<<2);
    vector <int> dx(N<<1, 0), dn(N<<1, N<<2);
    for(int i = 0; i < n; i ++) {
        mx[v[i].second] = max(mx[v[i].second], v[i].first);
        mn[v[i].second] = min(mn[v[i].second], v[i].first);
    }
    for(int i = 1; i < (N<<1); i ++) {
        dx[i] = max(dx[i-1], mx[i]);
        dn[i] = min(dn[i-1], mn[i]);
    }
    for(int i = (N<<1)-2; i >= 0; i --) {
        ux[i] = max(ux[i+1], mx[i]);
        un[i] = min(un[i+1], mn[i]);
    }
    long long ans = 0;
    for(int i = 0; i < (N<<1)-2; i ++) {
        int MX = min(ux[i+1], dx[i]), MN = max(un[i+1], dn[i]);
        if(MN < MX) ans += MX - MN;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector <pii> O, E;
    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        if(x + y & 1) O.push_back(pii((x+y+1)/2, (x-y+1)/2));
        else E.push_back(pii((x+y)/2, (x-y)/2));
    }
    cout << solve(E) + solve(O) << endl;
}