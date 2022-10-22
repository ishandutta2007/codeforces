#include <iostream>
using namespace std;

void draw(int i, int j, int k, int n, int m, string *s, string *t){
    for(int l = 0; l <= k; l++){
        int u = i - l, v = j - l;
        if(!(u >= 0 && v >= 0 && u < n && v < m && s[u][v] == '*')) return;
    }
    for(int l = 0; l <= k; l++){
        int u = i - l, v = j + l;
        if(!(u >= 0 && v >= 0 && u < n && v < m && s[u][v] == '*')) return;
    }
    for(int l = 0; l <= k; l++){
        int u = i - l, v = j - l;
        t[u][v] = '*';
    }
    for(int l = 0; l <= k; l++){
        int u = i - l, v = j + l;
        t[u][v] = '*';
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        string s[12], t[12];
        for(int i = 0; i < n; i++){
            cin >> s[i];
            for(int j = 0; j < m; j++) t[i] += '.';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int r = k; r <= i; r++) draw(i, j, r, n, m, s, t);
            }
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]) f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}