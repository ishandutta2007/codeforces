#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

struct P {
    int val, cnt;
};

int n;
map<int, int> mp;
vector<P> num;
ll res = 0;

void solve(int L, int R) {
    if(L == R) return ;

    int mid = (L + R) / 2;
    solve(L, mid);
    solve(mid + 1, R);
    vector<P> nxt;
    int r = mid + 1, sum = 0;
    for(int i = L; i <= mid; i++) {
        while(r <= R && num[r].val < num[i].val) {
            sum += num[r].cnt;
            nxt.push_back(num[r++]);
        }
        nxt.push_back(num[i]);
        res += 1LL * num[i].cnt * sum;
    }
    while(r <= R) {
        sum += num[r].cnt;
        nxt.push_back(num[r++]);
    }
    for(int i = L; i <= R; i++) num[i] = nxt[i - L];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(!mp.count(a)) mp[a] = a;
        if(!mp.count(b)) mp[b] = b;
        swap(mp[a], mp[b]);
    }
    int la = 0;
    for(auto p : mp) {
        if(p.first > la + 1) {
            num.push_back({la + 1, p.first - la - 1});
        }
        la = p.first;
        num.push_back({p.second, 1});
    }
    solve(0, num.size() - 1);
    cout << res << endl;

}