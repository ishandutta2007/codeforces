#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s[502];
        for(int i = 0; i < n; i++) cin >> s[i];
        char ans[502][502];
        int u;
        if(n % 3) u = 0;
        else u = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i % 3 == u || s[i][j] == 'X') ans[i][j] = 'X';
                else ans[i][j] = '.';
            }
        }
        for(int i = u + 1; i + 1 < n; i += 3){
            if(i % 3 == u) continue;
            if(m == 1 || (ans[i][1] == '.' && ans[i + 1][1] == '.')){
                ans[i][0] = 'X';
                ans[i + 1][0] = 'X';
            }
            else{
                ans[i][1] = 'X';
                ans[i + 1][1] = 'X';
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << ans[i][j];
            cout << endl;
        }
    }
}