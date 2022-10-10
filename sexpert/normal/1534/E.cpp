#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(vector<int> &v) {
    cout << "? ";
    for(auto x : v)
        cout << x << " ";
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void finish(int ans) {
    cout << "! " << ans << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(n % 2 == 1 && k % 2 == 0) {
        cout << "-1" << endl;
        return 0;
    }

    for(int cyc = 1;;cyc++) {
        if((cyc * k) % 2 != n % 2 || cyc * k < n)
            continue;
        vector<int> steps(n);
        fill(steps.begin(), steps.end(), 1);
        int rem = k * cyc - n, pt = 0;
        while(rem) {
            rem -= 2;
            steps[pt] += 2;
            pt = (pt + 1) % n;
        }
        if(steps[0] > cyc)
            continue;
        vector<int> ops;

        vector<vector<int>> cycs(cyc);
        priority_queue<array<int, 2>> q;
        for(int i = 0; i < cyc; i++)
            q.push({k, i});
        bool good = true;
        for(int i = 0; i < n; i++) {
            int x = steps[i];
            while(x--) {
                auto [cnt, pos] = q.top(); q.pop();
                if(cnt == 0) {
                    good = false;
                    break;
                }
                cnt--;
                q.push({cnt, pos});
                cycs[pos].push_back(i + 1);
            }
            if(!good)
                break;
        }
        if(!good)
            continue;
        int ans = 0;
        for(auto &v : cycs)
            ans ^= query(v);
        finish(ans);
    }
}