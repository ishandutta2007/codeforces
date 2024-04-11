#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]) ans++;
        }
        cout << ans << endl;
    }
}