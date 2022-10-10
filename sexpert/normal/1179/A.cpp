#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;

const int MAXN = 3e5 + 5;
ii ans[MAXN];
ll cs = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll n, q;
    cin >> n >> q;
    vector<int> v(n);
    deque<int> dq;
    for(auto &x : v) {
        cin >> x;
        dq.push_back(x);
    }
    int m = *max_element(v.begin(), v.end());
    vector<ii> qs;
    for(int i = 0; i < q; i++) {
        ll t;
        cin >> t;
        qs.push_back({t, i});
    }
    sort(qs.begin(), qs.end());
    for(auto p : qs) {
        ll t = p.first;
        while(cs < n && cs < t) {
            int a = dq[0], b = dq[1];
            dq.pop_front();
            dq.pop_front();
            if(a > b) {
                dq.push_front(a);
                dq.push_back(b);
            }
            else {
                dq.push_back(a);
                dq.push_front(b);
            }
            cs++;
            //for(int i = 0; i < n; i++)
            //    cout << dq[i] << " ";
            //cout << endl;
        }
        if(t <= n)
            ans[p.second] = {dq[0], dq[1]};
        else {
            //cout << 1 + (t - n - 1)%(n - 1) << " " << dq[1 + (t - n- 1)%(n - 1)] << endl;
            ans[p.second] = {dq[0], dq[1 + (t - n)%(n - 1)]};
        }
        //cout << (t - n - 1)%(n - 1) << endl;
    }
    for(int i = 0; i < q; i++)
        cout << ans[i].first << " " << ans[i].second << '\n';
}