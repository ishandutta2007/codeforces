#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 1;
    cin >> n;
    while(x <= n) {
        if(n == x || n == x + 1) return puts("1"), 0;
        if(x & 1) x = 2*x+2;
        else x = 2*x + 1;
    }
    puts("0");
}