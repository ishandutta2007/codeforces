#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int last = 0;
        int ans[300005];
        for(int i = 0; i <= n; i++) ans[i] = 0;
        for(int i = 1; i <= n; i++){
            if(i == n || s[i] == s[i - 1]){
                for(int j = last; j < i; j++){
                    if(s[j] == 'R') ans[j] = max(ans[j], i - last + 1);
                    else ans[j] = max(ans[j], 1);
                }
                if(s[i - 1] == 'L') ans[i] = i - last + 1;
                else ans[i] = 1;
                last = i;
            }
        }
        for(int i = 0; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}