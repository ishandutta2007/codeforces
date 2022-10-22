#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int e[10]{0};
        int r[200005];
        r[n] = n;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0') r[i] = r[i + 1];
            else r[i] = i;
        }
        if((r[1] == n && s[0] == '1') || (r[1] == n - 1 && s[0] == '1' && s[n - 1] == '1')){
            for(int j = 0; j < n - 2; j++) cout << '9';
            cout << endl;
            continue;
        }
        int l = 0;
        for(int i = 0; i < n; i++){
            int c = s[i] - '0';
            if(e[c]){
                e[c] = 0;
                l--;
            }
            else{
                e[c] = 1;
                l++;
            }
            if(n - r[i + 1] <= l){
                int x = 0;
                for(int j = 1; j < 10; j++) if(e[j]) x = x * 10 + j;
                int y = 0;
                for(int j = r[i + 1]; j < n; j++) y = y * 10 + (s[j] - '0');
                if(x >= y){
                    e[c] = 1 - e[c];
                    if((e[c] == 1 && n - (i + 1) <= l) || (e[c] == 0 && n - (i + 1) <= l - 2)){
                        for(int j = c - 1; j >= 0; j--){
                            if(e[j]){
                                e[j] = 0;
                                s[i] = char('0' + j);
                                break;
                            }
                        }
                    }
                    else{
                        e[c - 1] = 1 - e[c - 1];
                        s[i]--;
                    }
                    int k = n - 1;
                    for(int i = 0; i < 10; i++){
                        if(e[i]){
                            s[k] = char('0' + i);
                            k--;
                        }
                    }
                    for(; k > i; k--) s[k] = '9';
                    break;
                }
            }
        }
        cout << s << endl;
    }
}