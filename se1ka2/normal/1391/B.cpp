#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s[103];
        for(int i = 0; i < n; i++) cin >> s[i];
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i][m - 1] == 'R') ans++;
        }
        for(int j = 0; j < m - 1; j++){
            if(s[n - 1][j] == 'D') ans++;
        }
        cout << ans << endl;
    }
}