#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int l = 0;
        while(s[l] == '.') l++;
        int ans = 1;
        while(true){
            int i;
            for(i = min(n - 1, l + k); i > l; i--){
                if(s[i] == '*'){
                    ans++;
                    break;
                }
            }
            if(i == l) break;
            l = i;
        }
        cout << ans << endl;
    }
}