#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int l[200005], r[200005];
    int j = 0;
    for(int i = 0; i < n; i++){
        if(t[j] == s[i]){
            l[j] = i;
            j++;
            if(j == m) break;
        }
    }
    j = m - 1;
    for(int i = n - 1; i >= 0; i--){
        if(t[j] == s[i]){
            r[j] = i;
            j--;
            if(j == -1) break;
        }
    }
    int ans = 0;
    for(int j = 0; j <= m; j++){
        if(j == 0) ans = max(ans, r[0]);
        else if(j == m) ans = max(ans, n - l[m - 1] - 1);
        else ans = max(ans, r[j] - l[j - 1] - 1);
    }
    cout << ans << endl;
}