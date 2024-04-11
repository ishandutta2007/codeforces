#include<bits/stdc++.h>
using namespace std;
main(){

    int n;
    cin >> n;
    int s = 0, k =0;
    for(int i = 1; i <= n; i++){
            int a;
        cin >> a;
        k = max(k, a);
        s += a;
    }
    cout << max(k,(2*s / n + 1));
}