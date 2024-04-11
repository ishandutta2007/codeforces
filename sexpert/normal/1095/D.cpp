    #include <bits/stdc++.h>
    using namespace std;
     
    const int MAXN = 2e5 + 5;
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        pair<int, int> seen[MAXN];
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            seen[i] = {x, y};
        }
        if(n == 3) {
            cout << "1 2 3\n";
            return 0;
        }
        int nxt[MAXN];
        memset(nxt, 0, sizeof nxt);
        for(int i = 1; i <= n; i++) {
            if(nxt[i])
                continue;
            bool acan = false, bcan = false;
            int a = seen[i].first, b = seen[i].second;
            if(seen[a].first == b || seen[a].second == b)
                acan = true;
            if(seen[b].first == a || seen[b].second == a)
                bcan = true;
            if(acan && bcan) {
                nxt[i] = a;
                nxt[a] = b;
                nxt[b] = a;
                continue;
            }
            if(acan)
                nxt[i] = a;
            if(bcan)
                nxt[i] = b;
        }
        bool out[MAXN];
        int ansed = 0;
        for(int i = 0; i < MAXN; i++)
            out[i] = false;
        for(int i = 1; i <= n; i++) {
            if(out[i])
                continue;
            out[i] = true;
            cout << i << " ";
            int v = nxt[i];
            while(v != i) {
                cout << v << " ";
                out[v] = true;
                v = nxt[v];
            }
        }
        cout << endl;
    }