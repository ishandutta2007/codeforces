#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)2e5 + 50, INF = (int)1e9 + 50;

int n;
P p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first; p[i].second = i;
    }
    set<int> S;
    S.insert(-1);
    S.insert(n);
    sort(p, p + n, greater<>());
    int r = 0;
    for(int i = 0; i < n; ) {
        while(r < n && p[i].first == p[r].first) r++;
        for(int j = i; j < r; j++) {
            auto it = S.lower_bound(p[j].second);
            int rt = *it, lt = *(--it);
            if(lt == -1 && rt == n) break;
            if((rt - lt - 1) % 2 == 1) return cout << "NO" << endl, 0;
        }
        for(int j = i; j < r; j++) S.insert(p[j].second);
        i = r;
    }
    cout << "YES" << endl;

}