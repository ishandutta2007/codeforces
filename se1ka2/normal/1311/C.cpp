#include <iostream>
#include <string>
using namespace std;

int d[26][200005];

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for(int j = 0; j < 26; j++) d[j][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++) d[j][i] = d[j][i - 1];
            d[s[i - 1] - 'a'][i]++;
        }
        int ans[26]{0};
        for(int i = 0; i < m; i++){
            int p;
            cin >> p;
            for(int j = 0; j < 26; j++) ans[j] += d[j][p];
        }
        for(int j = 0; j < 26; j++) cout << ans[j] + d[j][n] << " ";
        cout << endl;
    }
}