#include<bits/stdc++.h>
using namespace std;

int trans(char *s) {
    long long ret = 0;
    for(int i = 0; s[i]; i ++) ret = 2 * ret + (s[i] & 1);
    return ret;
}

map <long long, int> mp;

int main() {
    int n;
    char t[3], s[30];
    scanf("%d", &n);
    while(n --) {
        scanf("%s%s", t, s);
        if(t[0] == '+') mp[trans(s)] ++;
        else if(t[0] == '-') mp[trans(s)] --;
        else printf("%d\n", mp[trans(s)]);
    }
}