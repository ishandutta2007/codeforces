#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int c = 0; c < k; c++){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int dif1 = -1, dif2 = -1;
        bool able = true;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                if(dif1 == -1) dif1 = i;
                else if(dif2 == -1) dif2 = i;
                else{
                    cout << "NO" << endl;
                    able = false;
                    break;
                }
            }
        }
        if(!able) continue;
        if(dif1 == -1) cout << "YES" << endl;
        else if(dif2 == -1) cout << "NO" << endl;
        else{
            if(s[dif1] == s[dif2] && t[dif1] == t[dif2]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}