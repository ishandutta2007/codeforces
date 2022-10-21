#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int res[360];

int main(){
    fill(res, res + 185, INF);
    for(int n = 3; n <= 360; n++){
        for(int x = 1; x <= n - 2; x++){
            if((180 * x) % n == 0) res[180 * x / n] = min(res[180 * x / n], n);
        }
    }
    int T;
    cin >> T;
    while(T--){
        int x;
        cin >> x;
        cout << res[x] << endl;
    }
}