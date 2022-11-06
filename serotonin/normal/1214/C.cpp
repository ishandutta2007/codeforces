#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

char s[sz];

int main()
{
    bool one=0;
    int n,x=0;
    scanf("%d %s", &n, s);

    for(int i=0; s[i]; i++) {
        if(s[i]=='(') x++;
        else x--;
        if(x<0) {
            if(!one) one=1, x=0;
            else {
                puts("No");
                return 0;
            }
        }
    }
    if(one) x--;
    if(x) puts("No");
    else puts("Yes");
}