#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<string> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        for (int _ = 0; _ < 2; _++){
            for (int j = 0; j < m; j++){
                printf("%c%c", a[j][i], a[j][i]);
            }
            puts("");
        }
    }

    return 0;
}