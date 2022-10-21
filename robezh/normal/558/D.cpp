#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 55;

ll pw[N];

set<pii>::iterator addInterval(set<pii>& is, ll L, ll R) {
    if (L == R) return is.end();
    auto it = is.lower_bound({L, R}), before = it;
    while (it != is.end() && it->first <= R) {
        R = max(R, it->second);
        before = it = is.erase(it);
    }
    if (it != is.begin() && (--it)->second >= L) {
        L = min(L, it->first);
        R = max(R, it->second);
        is.erase(it);
    }
    return is.insert(before, {L,R});
}

void removeInterval(set<pii>& is, ll L, ll R) {
    if (L == R) return;
    auto it = addInterval(is, L, R);
    auto r2 = it->second;
    if (it->first == L) is.erase(it);
    else (ll&)it->second = L;
    if (R != r2) is.emplace(R, r2);
}

int h, q;

int main() {
    ios::sync_with_stdio(false);
    
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i-1] * 2;
    cin >> h >> q;
    set<pii> S;
    addInterval(S, pw[h - 1], pw[h]);
    while(q--) {
        int i, ans;
        ll L, R;
        cin >> i >> L >> R >> ans;
        while(i < h) {
            L *= 2;
            R = R * 2 + 1;
            i++;
        }
        if(ans == 0) removeInterval(S, L, R + 1);
        else {
            removeInterval(S, 0, L);
            removeInterval(S, R + 1, pw[h]);
        }
    }
    if(S.empty()) cout << "Game cheated!" << endl;
    else {
        if(S.size() >= 2 || S.begin() -> second - S.begin() -> first > 1)
            cout << "Data not sufficient!" << endl;
        else cout << S.begin() -> first << endl;
    }

}