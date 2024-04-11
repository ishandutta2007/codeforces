#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = 0;
        if((m & n) == n){
            for(int j = 0; j < 30; j++){
                if((n >> j) & 1){
                    n -= (1 << j);
                }
                if(!((n >> j) & 1) && !((m >> j) & 1)){
                    ans += (1 << j);
                    n += (1 << j);
                    break;
                }
            }
        }
        for(int j = 29; j >= 0; j--){
            if(n > m) break;
            if(!((n >> j) & 1) && ((m >> j) & 1)){
                n += (1 << j);
                ans += (1 << j);
            }
        }
        cout << ans << endl;
    }
}