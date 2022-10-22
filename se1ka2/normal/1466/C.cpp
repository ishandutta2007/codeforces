#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        bool b[100005];
        for(int i = 0; i < n; i++) b[i] = false;
        for(int i = 0; i < n - 1; i++){
            if(b[i]) continue;
            if(s[i] == s[i + 1]){
                b[i + 1] = true;
                ans++;
            }
            if(i < n - 2 && s[i] == s[i + 2]){
                b[i + 2] = true;
                ans++;
            }
        }
        cout << ans << endl;
    }
}