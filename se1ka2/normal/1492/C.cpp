#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int l[200005], r[200005];
    int i = 0;
    for(int j = 0; j < m; j++){
        while(t[j] != s[i]) i++;
        if(t[j] == s[i]) l[j] = i;
        i++;
    }
    i = n - 1;
    for(int j = m - 1; j >= 0; j--){
        while(t[j] != s[i]) i--;
        if(t[j] == s[i]) r[j] = i;
        i--;
    }
    int ans = 0;
    for(int i = 0; i < m - 1; i++) ans = max(ans, r[i + 1] - l[i]);
    cout << ans << endl;
}