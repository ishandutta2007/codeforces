#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define N 200100

char s[N];
int n;

int main() {
    //freopen("in.txt", "r", stdin);
    gets(s);
    n = strlen(s);
    for(int i = 1; i < n; i ++) {
        if(s[i] == s[i-1]) {
            int k = s[i] - 'a';
            k = (k + 1) % 26;
            if(i < n - 1 && k == s[i+1] - 'a') k = (k + 1) % 26;
            s[i] = 'a' + k;
        }
    }
    puts(s);
    return 0;
}