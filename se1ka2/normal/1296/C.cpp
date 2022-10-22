#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<P, int> mp;
        int x = 0, y = 0;
        mp[P(0, 0)] = 1;
        int l = 0, r = n + 1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') x--;
            if(s[i] == 'R') x++;
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            if(mp[P(x, y)]){
                if(i + 1 - mp[P(x, y)] < r - l){
                    r = i + 1, l = mp[P(x, y)];
                }
            }
            mp[P(x, y)] = i + 2;
        }
        if(l != 0) cout << l << " " << r << endl;
        else cout << -1 << endl;
    }
}