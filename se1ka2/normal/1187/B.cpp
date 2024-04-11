#include <iostream>
#include <string>
using namespace std;

int a[26][200005];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        a[s[i] - 'a'][i]++;
        if(i > 0) for(int j = 0; j < 26; j++) a[j][i] += a[j][i - 1];
    }
    int m;
    cin >> m;
    for(int c = 0; c < m; c++){
        string t;
        cin >> t;
        int l = t.size();
        int b[26] {0};
        for(int i = 0; i < l; i++) b[t[i] - 'a']++;
        int ans = 0;
        for(int j = 0; j < 26; j++){
            int p = lower_bound(a[j], a[j] + n, b[j]) - a[j];
            ans = max(ans, p + 1);
        }
        cout << ans << endl;
    }
}