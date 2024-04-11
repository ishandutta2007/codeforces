#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, w;
        cin >> n >> w;
        int d[23]{0};
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            for(int j = 0; j < 20; j++){
                if((x >> j) & 1) d[j]++;
            }
        }
        int ans = 1;
        int l = w;
        while(true){
            bool f = true;
            bool g = true;
            for(int j = 19; j >= 0; j--){
                if(d[j]){
                    f = false;
                    if(l >= (1 << j)){
                        g = false;
                        while(l >= (1 << j) && d[j]){
                            l -= (1 << j);
                            d[j]--;
                        }
                    }
                }
            }
            if(f) break;
            else if(g){
                ans++;
                l = w;
            }
        }
        cout << ans << endl;
    }
}