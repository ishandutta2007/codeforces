    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int INF = 1e9;
     
    vector<vector<int>> a, d;
    vector<int> used, mt1, mt2, b;
    int t = 1;
    int v, n;
     
    bool kuhn(int u, int m, int deep) {
        if(used[u] == t)
            return false;
     
        used[u] = t;
     
        for(int i = 0; i < v; i++)
            if(d[u][i] <= m && mt2[i] == -1) {
                mt2[i] = u;
                mt1[u] = i;
                return true;
            }
     
        for(int i = 0; i < v; i++)
            if(d[u][i] <= m && kuhn(mt2[i], m, d[u][i])) {
                mt2[i] = u;
                mt1[u] = i;
                return true;
            }
        
        return false;
    }
     
    int matching(int m) {
        bool fl = true;
        //if(m == 3)
        while(fl) {
            fl = false;
            //if(m == 3)
            //cout<< "f" << endl;
            t++;
     
            for(int i = 0; i < n; i++) {
                if(mt1[i] == -1 && kuhn(i, m, 0))
                    fl = true;
            }
     
        }
     
        int res = 0;
        for(int i = 0; i < n; i++)
            res += (mt1[i] != -1);
     
        //cout << m << ' ' << res << endl;
        return res;
    }
     
    int main() {
        int e, k;
        cin >> v >>e >> n >> k;
     
        b.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
     
        a.resize(v, vector<int>(v, INF));
        for(int i = 0; i < e; i++) {
            int x, y, w;
            cin>> x >> y >> w;
            x--;
            y--;
     
     
            a[x][y] = min(a[x][y], w);
            a[y][x] = min(a[y][x], w);
        }
        
        for(int i = 0; i < v; i++)
            a[i][i] = 0;
            
       /* for(int i = 0; i < v;i++)
                for(int j = 0; j < v; j++)
                    cout << i << ' ' << j << ' ' << a[i][j] << endl;
                    */
        for(int k = 0; k < v; k++)
            for(int i = 0; i < v; i++)
                for(int j = 0; j < v; j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
           /*       
        for(int i = 0; i < v;i++)
            for(int j = 0; j < v; j++)
                cout << i << ' ' << j << ' ' << a[i][j] << endl;
        
        */
        d.resize(n, vector<int>(v, INF));
        mt1.resize(n, -1);
        mt2.resize(v, -1);
        used.resize(n, 0);
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < v; i++) {
                d[j][i] = a[b[j]][i];
                //cout << i << ' ' << j << ' ' << d[j][i] << endl;
            }
                
        }
        
     
        int l = -1, r = 2e6;
        while(r - l > 1) {
            int m = (r + l) / 2;
            //cout << l << ' ' << r << endl;
     
            t++;
            for(int i = 0; i < n;i++)
                mt1[i] = -1;
            for(int i = 0; i < v; i++)
                mt2[i] = -1;
            //cout << k << endl;
            if(matching(m) >= k)
                r = m;
            else
                l = m;
     
        }
     
        cout << (r == 2000000 ? -1 : r);
    }