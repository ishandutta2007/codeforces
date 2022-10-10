#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, int> df;
set<int> guys;
int cnt;

void add(int x) {
    if(guys.empty()) {
        guys.insert(x);
        return;
    }
    auto it = guys.upper_bound(x);
    if(it == guys.begin()) {
        df[*it - x]++;
        guys.insert(x);
        return;
    }
    if(it == guys.end()) {
        --it;
        df[x - *it]++;
        guys.insert(x);
        return;
    }
    int R = *it;
    --it;
    int L = *it;
    if(--df[R - L] == 0)
        df.erase(R - L);
    df[R - x]++;
    df[x - L]++;
    guys.insert(x);
}

void rem(int x) {
    guys.erase(x);
    auto it = guys.upper_bound(x);
    if(it == guys.begin()) {
        if(--df[*it - x] == 0)
            df.erase(*it - x);
        return;
    }
    if(it == guys.end()) {
        --it;
        if(--df[x - *it] == 0)
            df.erase(x - *it);
        return;
    }
    int R = *it;
    --it;
    int L = *it;
    if(--df[R - x] == 0)
        df.erase(R - x);
    if(--df[x - L] == 0)
        df.erase(x - L);
    df[R - L]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
    }

    auto dbg = []() {
        cout << "DEBUG INFO" << endl;
        for(auto x : guys)
            cout << x << " ";
        cout << endl;

        for(auto &[x, y] : df)
            cout << x << " " << y << endl;
    };

    cnt = n;
    auto ans = [&]() {
        if(cnt <= 2)
            return 0;
        return *(--guys.end()) - *(guys.begin()) - (--df.end())->first; 
    };

    cout << ans() << '\n';
    for(int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            cnt--;
            rem(x);
        }
        else {
            cnt++;
            add(x);
        }
        cout << ans() << '\n';
        //dbg();
    }
}