#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    string s[62];
    for(int i = 0; i < 60; i++) s[i] = to_string(1ll << i);
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        int k = n.size();
        int ans = 10000000;
        for(int c = 0; c < 60; c++){
            int l = s[c].size();
            int i = 0, j = 0;
            while(i < k && j < l){
                if(n[i] == s[c][j]) j++;
                i++;
            }
            ans = min(ans, k + l - j * 2);
        }
        cout << ans << endl;
    }
}