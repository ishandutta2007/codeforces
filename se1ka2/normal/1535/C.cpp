#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int i = 0, j = 0;
        int d[2]{0};
        ll ans = 0;
        while(j < n){
            while(i < n && !(d[0] && d[1])){
                if(s[i] != '?') d[(s[i] + i) % 2]++;
                i++;
            }
            if(d[0] && d[1]) ans += i - j - 1;
            else ans += i - j;
            if(s[j] != '?') d[(s[j] + j) % 2]--;
            j++;
        }
        cout << ans << endl;
    }
}