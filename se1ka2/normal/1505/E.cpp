#include <iostream>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    string s[5];
    for(int i = 0; i < h; i++) cin >> s[i];
    int x = 0, y = 0;
    int ans = 0;
    if(s[0][0] == '*') ans++;
    while(true){
        bool f = false;
        for(int k = 1; k <= h - x + w - y - 2; k++){
            for(int i = 0; i <= k; i++){
                if(x + i >= h || y + k - i >= w) continue;
                if(s[x + i][y + k - i] == '*'){
                    ans++;
                    x = x + i;
                    y = y + k - i;
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(!f) break;
    }
    cout << ans << endl;
}