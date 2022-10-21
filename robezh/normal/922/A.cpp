#include <bits/stdc++.h>
using namespace std;

int main() {
    int o,c;
    cin >> c >> o;
    if(o == 0) return !printf("No");
    if(o == 1 && c == 0) return !printf("Yes");
    if(o == 1) return !printf("No");

    if(((c-o) % 2 + 2) % 2 == 1 && c > o - 2) return !printf("Yes");
    return !printf("No");


}