#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n, x, y; cin >> n >> x >> y;
        int dif = y-x;
        int hi = 1;
        for(int i = 2; i <= n-1; ++i){
            if(!(dif%i))hi = i;
        }
        int z = hi;
        while(z < n-1 && x > dif/hi){
            x-=dif/hi;
            z++;
        }
        for(int i = x, cn = 0; cn < n; ++cn, i+=dif/hi){
            cout << i << " ";
        }
        cout << "\n";
    }
}