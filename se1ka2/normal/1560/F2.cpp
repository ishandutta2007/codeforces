#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n == 1000000000){
            if(k == 1) cout << 1111111111 << endl;
            else cout << 1000000000 << endl;
            continue;
        }
        string s = to_string(n);
        int p[10]{0};
        int l = s.size();
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < l; j++) p[i] = p[i] * 10 + i;
        }
        int b = (1 << k) - 1;
        string ans = "999999999";
        while(b < (1 << 10)){
            int x = 0;
            int y = 10;
            for(int i = 0; i < 10; i++){
                if((b >> i) & 1){
                    x = max(x, i);
                    y = min(y, i);
                }
            }
            if(n <= p[x]){
                string u;
                for(int i = 0; i < l; i++){
                    bool f = true;
                    if(!((b >> (s[i] - '0')) & 1)) f = false;
                    for(int j = i + 1; j < l; j++){
                        if(s[j] - '0' < x) break;
                        if(s[j] - '0' > x){
                            f = false;
                            break;
                        }
                    }
                    if(!f){
                        for(int j = s[i] - '0' + 1; j < 10; j++){
                            if((b >> j) & 1){
                                u += char(j + '0');
                                break;
                            }
                        }
                        for(int j = i + 1; j < l; j++) u += char(y + '0');
                        break;
                    }
                    u += s[i];
                }
                ans = min(ans, u);
            }
            int a = b & -b, c = b + a;
            b = ((b & ~c) / a >> 1) | c;
        }
        cout << ans << endl;
    }
}