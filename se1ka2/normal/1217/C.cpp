#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        int now = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') now++;
            if(s[i] == '1'){
                int k = 1;
                now++;
                int j = i + 1;
                while(k <= now){
                    ans++;
                    if(j >= n) break;
                    k *= 2;
                    k += s[j] - '0';
                    now++;
                    j++;
                }
                now = 0;
            }
        }
        cout << ans << endl;
    }
}