#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s[1002];
    for(int i = 0; i < n; i++) cin >> s[i];
    int a[1002];
    for(int i = 0; i < m; i++) cin >> a[i];
    int ans = 0;
    for(int j = 0; j < m; j++){
        int b[5] {0};
        for(int i = 0; i < n; i++){
            b[s[i][j] - 'A']++;
        }
        int l = 0;
        for(int k = 0; k < 5; k++) l = max(l, b[k]);
        ans += a[j] * l;
    }
    cout << ans << endl;
}