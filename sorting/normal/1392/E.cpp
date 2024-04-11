#include <bits/stdc++.h>

using namespace std;

const int k_N = 25 + 3;

long long a[k_N][k_N];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= 2 * n - 1; ++i){
        int x, y;
        if(i <= n) x = i, y = 1;
        else x = n, y = i - (n - 1);

        int cnt = 0;
        while(x >= 1 && y <= n){
            //cout << x << " " << y << " x y" << endl;
            //cout << cnt << " cnt" << endl;
            if(cnt & 1) a[x][y] = (1ll << (i - 1));
            else a[x][y] = 0;
            x--, y++;
            cnt++;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
        fflush(stdout);
    }

    int q;
    cin >> q;

    while(q--){
        long long k;
        cin >> k;

        int cnt = 1;
        int x = 1, y = 1;
        while(x != n || y != n){
            cout << x << " " << y << "\n";
            fflush(stdout);

            if(x == n) y++;
            else if(y == n) x++;
            else{
                long long t = (1ll << cnt) & k;
                //cout << t << " t" << "\n";
                if(a[x + 1][y] == t) x++;
                else y++;
            }
            cnt++;
        }
        cout << x << " " << y << "\n";
        fflush(stdout);
    }
}