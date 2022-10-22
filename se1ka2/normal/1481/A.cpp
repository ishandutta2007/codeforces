#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int n = s.size();
        int d[4]{0};
        for(int i = 0; i < n; i++){
            if(s[i] == 'R') d[0]++;
            if(s[i] == 'L') d[1]++;
            if(s[i] == 'U') d[2]++;
            if(s[i] == 'D') d[3]++;
        }
        bool f = true;
        if(x < 0 && d[1] < abs(x)) f = false;
        if(x > 0 && d[0] < x) f = false;
        if(y < 0 && d[3] < abs(y)) f = false;
        if(y > 0 && d[2] < y) f = false;
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}