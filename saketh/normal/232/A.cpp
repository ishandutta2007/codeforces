#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
bool g[100][100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < i; j++) {
            int a = 0;
            for (int k = 0; k < 100; k++) {
                if (g[i][k] && g[k][j]) a++;
            }

            if(a > N) continue;
            g[i][j] = true;
            g[j][i] = true;
            N -= a;
        }
    }

    cout << 100 << "\n";
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << ( g[i][j] ? "1" : "0" );
        }
        cout << "\n";
    }
}