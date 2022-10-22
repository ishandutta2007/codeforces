#include <iostream>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    string ans = "";
    ans += char('z' + 1);
    for(int i = 1; i <= n; i++){
        string t = "";
        while((int)t.size() < k) t += s.substr(0, i);
        t = t.substr(0, k);
        ans = min(ans, t);
    }
    cout << ans << endl;
}