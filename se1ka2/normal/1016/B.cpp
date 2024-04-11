#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    if(m > n){
        for(int i = 0; i < q; i++) cout << 0 << endl;
        return 0;
    }
    string s, t;
    cin >> s >> t;
    int u[1002]{0};
    for(int i = 0; i < n - m + 1; i++){
        u[i + 1] = u[i];
        int j;
        for(j = 0; j < m; j++){
            if(s[i + j] != t[j]) break;
        }
        if(j == m) u[i + 1]++;
    }
    for(int c = 0; c < q; c++){
        int l, r;
        cin >> l >> r;
        if(r - m + 1 < l - 1) cout << 0 << endl;
        else cout << u[r - m + 1] - u[l - 1] << endl;
    }
}