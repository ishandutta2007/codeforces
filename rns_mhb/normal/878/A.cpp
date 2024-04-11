#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x = 0, y = 1023;
    cin >> n;
    while(n --) {
        string s;
        int z;
        cin >> s >> z;
        if(s == "&") x &= z, y &= z;
        if(s == "|") x |= z, y |= z;
        if(s == "^") x ^= z, y ^= z;
    }
    int a = 1023, b = 0, c = 0;
    for(int i = 0; i < 10; i ++) {
        if((x>>i&1) && (y>>i&1)) b ^= 1<<i;
        if((x>>i&1) && !(y>>i&1)) c ^= 1<<i;
        if(!(x>>i&1) && !(y>>i&1)) a ^= 1<<i;
    }
    cout << 3 << endl;
    cout << "& " << a << endl;
    cout << "| " << b << endl;
    cout << "^ " << c << endl;
}