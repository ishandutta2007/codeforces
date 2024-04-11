#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;
        int ans[22][22];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++) ans[i][j] = 0;
        }
        for(int j = 0; j < w; j += 2) ans[0][j] = ans[h - 1][j] = 1;
        for(int i = 2; i < h - 2; i += 2) ans[i][0] = ans[i][w - 1] = 1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++) cout << ans[i][j];
            cout << endl;
        }
    }
}