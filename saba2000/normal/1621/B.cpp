#include<bits/stdc++.h>
using namespace std;

int n;


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long L = 2e9, R = -1, M = 2e9, ml = 2e9, mr = 2e9;
        for(int i = 1; i <= n; i++){
            long long l, r, c;
            cin >> l >> r >> c;
            if(l < L) L = l, ml = 2e9, M = 2e9;
            if(r > R) R = r, mr = 2e9, M = 2e9;
            if(l == L) ml = min(ml, c);
            if(r == R) mr = min(mr, c);
            if(l == L && r == R) M = min(M, c);
            cout << min(ml + mr, M) << endl;


        }
    }


}