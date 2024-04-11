#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool can(int u, int v) {
    //cout << u << " " << v << endl;
    vector<int> ru, rv;
    for(int b = 0; b < 30; b++) {
        if((u >> b) & 1)
            ru.push_back(b);
        if((v >> b) & 1)
            rv.push_back(b);
    }
    if(u > v)
        return false;
    /*for(auto &b : ru)
        cout << b << " ";
    cout << '\n';
    for(auto &b : rv)
        cout << b << " ";
    cout << '\n';*/
    if(rv.size() > ru.size())
        return false;
    /*if(ru.size() > rv.size()) {
        int tk = ru.size() - rv.size() + 1;
        int cnt = 0;
        for(int b = 0; b <= 30; b++) {
            if((u >> b) & 1) {
                cnt++;
                continue;
            }
            else {
                if(cnt < tk)
                    continue;
                int rm = tk, ms = u + (1 << b);
                for(int c = b - 1; c >= 0; c--) {
                    if(rm == 0)
                        break;
                  if((u >> c) & 1) {
                        rm--;
                        ms ^= (1 << c);
                    }
                }
                return can(ms, v);
            }
        }
    }
    for(int i = 0; i < ru.size(); i++)
        if(ru[i] > rv[i])
            return false;*/
    reverse(rv.begin(), rv.end());
    for(int b = 30; b > rv[0]; b--) {
        if((u >> b) & 1)
            return false;
    }
    int p = 30;
    for(int i = 0; i < rv.size(); i++) {
        while(p > rv[i])
            p--;
        while(p >= 0 && ((u >> p) & 1) == 0)
            p--;
        if(p == -1)
            return false;
        p--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(can(u, v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}