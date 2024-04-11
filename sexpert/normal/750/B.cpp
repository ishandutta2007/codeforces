#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, pos = 10000;
    bool valid = true;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        string dir;
        cin >> x >> dir;
        if(pos == 10000 && dir != "South")
            valid = false;
        if(pos == -10000 && dir != "North")
            valid = false;
        if(dir == "East" || dir == "West")
            continue;
        if(dir == "North")
            pos = pos + x;
        if(dir == "South")
            pos = pos - x;
        if(pos < -10000)
            valid = false;
        if(pos > 10000)
            valid = false;
        //cout << pos << endl;
    }
    if(pos != 10000)
        valid = false;
    cout << (valid ? "YES\n" : "NO\n");
}