#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int t;
int n,x,y,d;


int main(){
    cin >> t;
    while(t--){
        cin >> n >> x >> y >> d;
        int ans = INF;
        if(abs(x - y) % d == 0) ans = min(ans, abs(x - y) / d);
        if(abs(y - 1) % d == 0) ans = min(ans, (x - 1) / d + 1 + (y - 1) / d);
        if((n - y) % d == 0) ans = min(ans, (n - x - 1) / d + 1 + (n - y) / d);
        cout << (ans == INF ? -1 : ans) << endl;
    }
}