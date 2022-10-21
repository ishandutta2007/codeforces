#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 50;

int n;
P p[N];
int S[N], sz = 0;
vector<P> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n, greater<P>());
    for(int i = 0; i < n - 1; i++) {
        res.push_back({2 * p[i].second, 2 * p[i+1].second});
    }
    for(int i = 0; i < n; i++) {
        S[sz++] = 2 * p[i].second;
    }
    for(int i = 0; i < n; i++) {
        int len = p[i].first;
        res.push_back({2 * p[i].second + 1, S[i + len - 1]});
        if(i + len >= sz) S[sz++] = 2 * p[i].second + 1;
    }
    for(P p : res) cout << p.first + 1 << " " << p.second + 1 << "\n";

}