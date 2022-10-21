#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;


int main() {
    int n,m;
    cin >> n >> m;
    int fir = 100003/(n-1) + 1;
    cout << "100003 100003\n";
    for(int i = 1; i <= 100003 % (n-1); i++){
        printf("%d %d %d\n", i, i+1, fir);
    }
    for(int i = 100003 % (n-1) + 1; i <= n-1; i++){
        printf("%d %d %d\n", i , i+1, fir-1);
    }
    int cnt = m-n+1;
    if(cnt == 0) return 0;
    for(int t = 1; t <= n; t++){
        for(int k = t+2; k <= n; k++){
            printf("%d %d %d\n", t, k, INF);
            cnt --;
            if(cnt == 0) return 0;
        }
    }
}