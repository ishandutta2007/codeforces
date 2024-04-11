#include<bits/stdc++.h>
using namespace std;
int a[309][309];
main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k % n == 0){
            cout << 0 << endl;
            int x = k / n;
            for(int i = 1; i <= n; i++){
                for(int j = i; j < i + x; j++)
                    a[i][j%n+1] = 1;
            }
            for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= n; j++){
                    cout << a[i][j];
                    a[i][j] = 0;
                }
                cout<<endl;
            }
        }
        else{
            cout << 2 << endl;
            int x = k / n + 1;
            int y = x * n - k;
            for(int i = 1; i <= n; i++){
                for(int j = i; j < i+x; j++)
                    a[i][j%n+1] = 1;
            }
            for(int i = 1; i <= y; i++)
                a[i][i%n+1] = 0;
            for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= n; j++){
                    cout << a[i][j];
                    a[i][j] = 0;
                }
                cout<<endl;
            }

        }

    }

}