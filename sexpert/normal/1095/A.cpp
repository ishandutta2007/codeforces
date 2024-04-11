    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n;
        string s;
        cin >> n >> s;
        int ct = 0, i = 1;
        while(ct < n) {
            cout << s[ct];
            ct += i;
            i++;
        }
        cout << endl;
    }