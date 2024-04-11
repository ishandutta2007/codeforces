#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=105;

char a[sz],b[sz],c[sz];

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        scanf("%s %s %s", a, b, c);
        bool no=0;
        for(int i=0; a[i]; i++) {
            if(a[i]==c[i] || b[i]==c[i]) continue;
            no=1;
        }
        if(no) puts("NO");
        else puts("YES");
    }
}