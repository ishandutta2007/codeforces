#include<bits/stdc++.h>
using namespace std;

int main() {
    char x[111], y[111];
    scanf("%s%s", x, y);
    for(int i = strlen(x) - 1; i >= 0; i --) if(x[i] < y[i]) {puts("-1"); return 0;}
    puts(y);
}