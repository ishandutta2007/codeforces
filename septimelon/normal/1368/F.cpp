#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    int maxa = 0;
    int maxu = 1;
    for (int u = 2; u * u <= n; ++u) {
        int cmax = (u - 1) * (n / u) - (u - 1);
        if (n % u != 0) {
            cmax += (n % u) - 1;
        }
        if (cmax > maxa) {
            maxa = cmax;
            maxu = u;
        }
    }
    
    vector<int> des;
    vector<bool> fir(n + 1, false);
    for (int i = maxu * maxu + 1; i < n; ++i) {
        if (i % maxu != 0) {
            des.push_back(i);
        }
    }
    int ci = 0;
    int fire = 0;
    
    for (int q = 1; q < maxu; ++q) {
        cout << maxu;
        for (int i = 0; i < maxu; ++i) {
            cout << " " << maxu * i + q;
            fir[maxu * i + q] = true;
        }
        cout << endl;
        fire += maxu;
        int rez;
        cin >> rez;
        if (rez == -1) {
            return 0;
        }
        for (int i = 0; i < maxu; ++i) {
            int crez = rez + i;
            if (crez > n) {
                crez -= n;
            }
            if (fir[crez]) {
                fir[crez] = false;
                --fire;
                des.push_back(crez);
            }
        }
    }
    
    while (des.size() - ci >= maxu) {
        cout << maxu;
        for (int i = 0; i < maxu; ++i) {
            cout << " " << des[ci + i];
            fir[des[ci + i]] = true;
        }
        cout << endl;
        fire += maxu;
        ci += maxu;
        int rez;
        cin >> rez;
        if (rez == -1) {
            return 0;
        }
        for (int i = 0; i < maxu; ++i) {
            int crez = rez + i;
            if (crez > n) {
                crez -= n;
            }
            if (fir[crez]) {
                fir[crez] = false;
                --fire;
                des.push_back(crez);
            }
        }
    }
    
    cout << "0" << endl;
    
    return 0;
}