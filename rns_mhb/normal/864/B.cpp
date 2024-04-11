#include<bits/stdc++.h>
using namespace std;

int d, b[30];

void format()
{
    d = 0;
    for(int i = 0; i < 26; i ++) b[i] = 0;
}

int main()
{
    int n, rlt = 0, i;
    char s[300];

    scanf("%d\n", &n);
    gets(s);
    format();
    for(i = 0; i < strlen(s); i ++) {
        if('A' <= s[i] && s[i] <= 'Z') {
            format();
        }
        if('a' <= s[i] && s[i] <= 'z') {
            if(b[s[i] - 'a'] == 0) {
                    b[s[i] - 'a'] = 1;
                    d ++;
                    rlt = max(rlt, d);
            }
        }
    }
    printf("%d\n", rlt);
}