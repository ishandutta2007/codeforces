#include<bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, m;
char s[N];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        for(int i = 0; i < n; ) {
            if(s[i] == '0') {
                int j = i;
                while(s[j] == '0' && j < n) j ++;
                if(i == 0 && j == n) break;
                if(i == 0) {
                    for(int k = j - 1; k >= max(j - m, 0); k --) s[k] = '1';
                }
                else if(j == n) {
                    for(int k = i; k < min(i + m, n); k ++) s[k] = '1';
                }
                else {
                    int d = j - i >> 1;
                    for(int k = i; k < i + min(d, m); k ++) s[k] = '1';
                    for(int k = j - 1; k >= j - min(d, m); k --) s[k] = '1';
                }
                i = j;
            }
            else i ++;
        }
        printf("%s\n", s);
    }
}