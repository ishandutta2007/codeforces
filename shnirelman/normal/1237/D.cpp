#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int M = 1e9 + 7;
//const int ln = 20;
const int k = 3;
const int N = 1e5 + 14;



int t[4 * k * N];

int n;
vector<int> a;

void build(int v, int l, int r) {
    if(r - l == 1) {
        t[v] = a[l % n];
        return;
    }
    
    int m = (r + l) / 2;
    
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int l, int r, int ql, int qr, int x) {
    if(ql >= r || l >= qr)
        return -1;
    
    if(t[v] <= x)
        return -1;
    
    if(r - l == 1) {
        if(t[v] > x)
            return l;
        else
            return -1;
    }
    
    int m = (r + l) / 2;
    int mx = get(v * 2 + 2, m, r, ql, qr, x);
    if(mx != -1)
        return mx;
        
    return get(v * 2 + 1, l, m, ql, qr, x);
}

int main() {
    cin >> n;
    
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    {
        int mx = a[0], mn = a[1];
        for(int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        
        
        if(mn * 2 >= mx) {
            for(int i = 0; i < n; i++)
                cout << -1 << ' ';
            return 0;
        }
    }
    
    build(0, 0, n * k);
    
    vector<vector<int>> b(n * k);
    for(int i = 0; i < n * k; i++) {
        int res = get(0, 0, k * n, 0, i, a[i % n] * 2);
        
       // cout << i << ' ' << res << endl;
        
        if(res != -1)
            b[res].push_back(i);
    }
    
    vector<int> c(n);
    int mn = k * n;
    for(int i = n * k - 1; i >= 0; i--) {
        int cur = 1e9;
        for(auto b1 : b[i])
            cur = min(cur, b1);
            
        mn = min(mn, cur);
        
        //cout << i <<' ' << mn << endl;
        
        if(i < n)
            c[i] = mn - i;
    }
    
    for(auto c1 : c)
        cout << c1 << ' ';
    //cout << "bsdnb" << endl;
    /*vector<int> max2(n + 1, 0);
    max2[1] = 0;
    for(int i = 2; i <= n; i++)
        max2[i] = max2[i / 2] + 1;
    
    vector<vector<int>> mx(ln, vector<int>(n * 2)), mn(ln, vector<int>(n));
    for(int i = 0; i < n * 2; i++) {
        mx[0][i] = mn[0][i] = a[i % n];
    }
    //cout << "fsdf" << endl;
    for(int i = 1; i < ln; i++)
        for(int j = 0; j + (1 << i) <= n * 2; j++) {
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
        }
    
    //cout << mx[1][0]
    
    //cout << "fsdf" << endl;
    for(int i = 0; i < n; i++) {
        int l = 1, r = n;
        while(r - l > 1) {
            int m = (r + l) / 2;
            cout << l << ' ' << r << ' ' << i << ' ' << m << ' ' << max2[m] << endl;
            //cout << mn[i][max2[m]] << ' ' << mx[i][max2[m]] << endl;
            //if(mn[i][max2[m]] * 2 < mx[i][max2[m]])
            if(mn[max2[m]][i] * 2 < mx[max2[m]][i])
                r = m;
            else
                l = m;
                
            cout << l << ' ' << r << endl;
        }
        
        cout << l << ' '; 
    }*/
}