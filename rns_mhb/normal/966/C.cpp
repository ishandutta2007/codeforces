#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100010

int n;
vector <ll> v[66];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        ll x, y;
        cin >> x; y = x;
        int k = 0;
        while(x > 0) x >>= 1, k ++; k --;
        v[k].push_back(y);
    }
    vector <int> id;
    for(int i = 64; i >= 0; i --) if(v[i].size() > 0) id.push_back(i);
    if(v[id[0]].size() > 1) {
        puts("No");
        return 0;
    }
    vector <int> pos(n);
    vector <ll> ans;
    ans.push_back(v[id[0]][0]);
    for(int i = 1; i < id.size(); i ++) {
        int x = id[i];
        vector <ll> nxt;
        nxt.push_back(v[x][0]);
        int k = 1;
        for(int j = 0; j < ans.size(); j ++) {
            nxt.push_back(ans[j]);
            if(k < v[x].size() && (ans[j]>>x&1)) nxt.push_back(v[x][k++]);
        }
        if(k < v[x].size()) {
            puts("No");
            return 0;
        }
        ans = nxt;
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n; i ++) cout << ans[i] << ' ';
    cout << endl;
}