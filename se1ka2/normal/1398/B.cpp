#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        s += '.';
        int n = s.size();
        int d[105]{0};
        int c = 0;
        int l = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') l++;
            else{
                d[c] = l;
                l = 0;
                c++;
            }
        }
        sort(d, d + c, greater<int>());
        int ans = 0;
        for(int i = 0; i < c; i += 2) ans += d[i];
        cout << ans << endl;
    }
}