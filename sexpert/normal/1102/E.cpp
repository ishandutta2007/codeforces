    #include <bits/stdc++.h>
    using namespace std;
    typedef pair<int, int> ii;
    typedef long long ll;
     
    const int MAXN = 2e5 + 5;
    const ll MOD = 998244353;
    vector<ii> intervals;
    map<int, int> fst, lst;
    int a[MAXN];
     
    ll mpow(ll b, ll e) {
        if(e == 0)
            return 1;
        if(e % 2)
            return (b * mpow(b, e - 1)) % MOD;
        ll p = mpow(b, e/2);
        return (p * p) % MOD;
    }
     
    int main() {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++) {
            if(!fst.count(a[i]))
                fst[a[i]] = i;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(!lst.count(a[i]))
                lst[a[i]] = i;
        }
        for(auto p : fst) {
            int u = p.first;
            intervals.push_back({fst[u], lst[u]});
        }
        sort(intervals.begin(), intervals.end());
        ll disj = intervals.size();
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].first <= intervals[i - 1].second) {
                disj--;
                intervals[i].first = intervals[i - 1].first;
                intervals[i].second = max(intervals[i].second, intervals[i - 1].second);
            }
        }
        cout << mpow(2ll, disj - 1) << endl;
    }