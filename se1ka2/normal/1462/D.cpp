#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int s = 0;
        int a[3005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        int k;
        for(k = n; k >= 1; k--){
            if(s % k) continue;
            int c = 0;
            bool f = true;
            for(int i = 0; i < n; i++){
                c += a[i];
                if(c > s / k){
                    f = false;
                    break;
                }
                if(c == s / k) c = 0;
            }
            if(f) break;
        }
        cout << n - k << endl;
    }
}