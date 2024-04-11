#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[102];
    for(int i = 0; i < n; i++) cin >> a[i];
    while(true){
        int s = 0, o = -1;
        for(int i = 0; i < n; i++){
            if(a[i] % 2) o = i;
            s += a[i];
        }
        if(s % 2){
            cout << 0 << endl;
            return 0;
        }
        if(o != -1){
            bool dp[200002]{0};
            dp[0] = true;
            for(int i = 0; i < n; i++){
                bool d[200002]{0};
                for(int j = 0; j <= 200000; j++) d[j] = dp[j];
                for(int j = a[i]; j <= 200000; j++){
                    if(d[j - a[i]]) dp[j] = true;
                }
            }
            if(!dp[s / 2]){
                cout << 0 << endl;
            }
            else{
                cout << 1 << endl;
                cout << o + 1 << endl;
            }
            return 0;
        }
        for(int i = 0; i < n; i++) a[i] /= 2;
    }
}