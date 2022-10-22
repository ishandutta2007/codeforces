#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        map<string, int> mp;
        string p[12];
        string s[12];
        for(int i = 0; i < n; i++) s[i] = "";
        for(int i = 0; i < n; i++){
            cin >> p[i];
            if(mp[p[i]] == 0){
                mp[p[i]]++;
                s[i] = p[i];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ""){
                ans++;
                for(int j = 0; j < 10; j++){
                    p[i][3] = '0' + j;
                    if(mp[p[i]] == 0){
                        mp[p[i]]++;
                        s[i] = p[i];
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
        for(int i = 0; i < n; i++) cout << s[i] << endl;
    }
}