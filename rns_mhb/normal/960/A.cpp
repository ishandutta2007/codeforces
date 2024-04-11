#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 1; i < n; i ++) if(s[i-1] > s[i]) {
        puts("NO");
        return 0;
    }
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'a') a ++;
        if(s[i] == 'b') b ++;
        if(s[i] == 'c') c ++;
    }
    if(a != c && b != c) {
        puts("NO");
        return 0;
    }
    if(a == 0 || b == 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
}