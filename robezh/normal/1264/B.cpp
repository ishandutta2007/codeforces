#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int c[4];
int n;
vector<int> res;

int main() {
    for(int i = 0; i < 4; i++) {
        cin >> c[i];
        n += c[i];
    }
    res.resize(n, 0);
    int odd = c[1] + c[3], even = c[0] + c[2];
    if(abs(odd - even) > 1) return cout << "NO" << endl, 0;
    if(odd >= even) for(int i = 0; i < n; i += 2) res[i] = 1;
    else for(int i = 1; i < n; i += 2) res[i] = 1;

    for(int i = 0; i < n; i += 2) {
        if(res[i]) {
            if(c[3]) res[i] = 3, c[3]--;
            else res[i] = 1, c[1]--;
        }
        else {
            if(c[0]) res[i] = 0, c[0]--;
            else res[i] = 2, c[2]--;
        }
    }
    int la = n - 1;
    if(la % 2 == 0) la--;
    for(int i = la; i >= 0; i -= 2) {
        if(res[i]) {
            if(c[3]) res[i] = 3, c[3]--;
            else res[i] = 1, c[1]--;
        }
        else {
            if(c[0]) res[i] = 0, c[0]--;
            else res[i] = 2, c[2]--;
        }
    }
    if(c[0] || c[3]) return cout << "NO" << endl, 0;
    for(int i = 0; i < n - 1; i++) {
        if((res[i] == 0 && res[i+1] == 3) || (res[i] == 3 && res[i+1] == 0))
            return cout << "NO" << endl, 0;
    }
    
    cout << "YES" << endl;
    for(int x : res) cout << x << " ";
    cout << endl;



}