#include<bits/stdc++.h>
using namespace std;

#define N 1000

char s[N];

void solve(int l, int r) {
    if(r < l) return;
    int len = r - l + 1;
    if(len & 1) solve(l+1, r), putchar(s[l]);
    else solve(l, r-1), putchar(s[r]);
}

int main() {
    scanf("%s", s);
    int len = strlen(s);
    solve(0, len-1);
    putchar('\n');
}