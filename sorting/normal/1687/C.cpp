#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    
    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n + 1), b(n + 1);
        for(ll i = 1; i <= n; ++i)
            cin >> a[i];
        for(ll i = 1; i <= n; ++i)
            cin >> b[i];

        vector<pair<ll, ll>> ranges(m);
        for(ll i = 0; i < m; ++i){
            cin >> ranges[i].first >> ranges[i].second;
            --ranges[i].first;
        }

        for(int i = 1; i <= n; ++i){
            a[i] = a[i] - b[i];
            a[i] += a[i - 1];
        }

        // for(int i = 0; i <= n; ++i)
            // cout << a[i] << " ";
        // cout << " a" << endl;

        queue<int> q;
        vector<int> cnt(m);
        vector<vector<int>> add(n + 1);
        for(int i = 0; i < m; ++i){
            cnt[i] += a[ranges[i].first] == 0;
            cnt[i] += a[ranges[i].second] == 0;

            add[ranges[i].first].push_back(i);
            add[ranges[i].second].push_back(i);

            if(cnt[i] == 2)
                q.push(i);
        }

        set<int> s;
        for(int i = 0; i <= n; ++i)
            if(a[i])
                s.insert(i);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            auto r = s.upper_bound(ranges[u].second);
            auto l = s.lower_bound(ranges[u].first);
            if(r == s.begin())
                continue;
            if(r == l)
                continue;
            --r;

            // cout << u << " u" << endl;

            while(true){
                auto nxt = r;
                --nxt;

                a[*r] = 0;
                for(int x: add[*r]){
                    ++cnt[x];
                    if(cnt[x] == 2)
                        q.push(x);
                }

                s.erase(r);

                if(r == l)
                    break;
                r = nxt;
            }
        }

        if(s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}