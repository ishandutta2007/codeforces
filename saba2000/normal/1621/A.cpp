#include<bits/stdc++.h>
using namespace std;

int n;

main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if (n < 2 * k - 1){
            cout << -1<<endl;
            continue;
        }
        for(int i =1 ; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i <= 2*k - 1 && i == j && i % 2 == 1){
                    cout <<'R';
                }
                else cout<<'.';
            }
            cout<<endl;
        }
    }


}