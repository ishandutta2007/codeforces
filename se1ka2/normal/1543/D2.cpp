#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll p[33];
        p[0] = 1;
        for(int i = 1; i < 30; i++) p[i] = p[i - 1] * k;
        ll s[33];
        s[0] = 1;
        for(int i = 1; i < 30; i++) s[i] = s[i - 1] + p[i];
        for(int i = 0; i <= n; i++){
            ll c;
            if(i == 0) c = 0;
            else{
                int b = i;
                for(int j = 0; j < 30; j++){
                    if(b % k){
                        c = s[j];
                        break;
                    }
                    b /= k;
                }
                if(i % 2) c *= k - 1;
            }
            cout << c << endl;
            int r;
            cin >> r;
            if(r == 1) break;
            if(r == -1) return 0;
        }
    }
}