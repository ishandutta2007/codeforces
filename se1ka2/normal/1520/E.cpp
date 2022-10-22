#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int d[1000006];
        int k = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '*') d[k++] = i;
        }
        ll ans = 0;
        for(int i = 0; i < k; i++) ans += abs(d[k / 2] - d[i]) - abs(k / 2 - i);
        cout << ans << endl;
    }
}