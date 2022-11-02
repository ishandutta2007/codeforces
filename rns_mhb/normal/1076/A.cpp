#include<bits/stdc++.h>
using namespace std;

char s[200010];

int main() {
    int n;
    scanf("%d%s", &n, s);
    int j = 0;
    for(int i = 0; i < n; i ++) if(s[i] > s[i+1]) {j=i; break;}
    for(int i = 0; i < n; i ++) if(i != j) putchar(s[i]);
    putchar('\n');
}