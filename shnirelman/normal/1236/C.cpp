#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int res = 0;
    while(b >= 1 && c >= 2) {
        b--;
        c -= 2;
        res += 3;
    }
    
    while(a >= 1 && b >= 2) {
        a--;
        b -= 2;
        res += 3;
    }
    
    cout << res << endl;
}

int pow(int n, int k) {
    if(k == 0)
        return 1;
        
    if(k == 1)
        return n;
        
    int pw = pow(n, k / 2);
    if(k % 2)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

vector<vector<int>> b;

bool cmp(int i, int j) {
    return b[i][j] > b[j][i];
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n);
    vector<int> cnt(n, 0);
    b.resize(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        vector<int> p(n);
        for(int j = 0; j < n; j++)
            p[j] = j;
            
        sort(p.begin(), p.end(), cmp);
        
        for(int j = 0; j < n; j++) {
            int bl = p[j], l = j;
            a[bl].push_back(l + i * n);
            
            for(int k = 0; k < n; k++) {
                b[bl][k] += cnt[k];
            }
            
            cnt[bl]++;
        }
        
        
    }
    
    for(auto a1 : a) {
        for(auto a2 : a1)
            cout << a2 + 1 << ' ';
        cout << endl;
    }
}