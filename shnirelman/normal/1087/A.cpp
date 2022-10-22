#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    if(s.length() == 1){
        cout << s;
        return 0;
    }

    string s1 = "";
    int l = (s.length() - 1) / 2;
    int r = l + 1;
    while(l >= 0){
        s1 += s[l];
        if(r < s.length())s1 += s[r];
        l--;
        r++;

    }

    cout << s1;
}