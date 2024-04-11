#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5, inf=2e9+5;

char s[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d %s", &n, s);
        if(n==2) {
            if(s[0]>=s[1]) puts("NO");
            else {
                puts("YES");
                puts("2");
                printf("%c %c\n", s[0], s[1]);
            }
        }
        else {
            puts("YES");
            puts("2");
            printf("%c ", s[0]);
            for(int i=1; i<n; i++) printf("%c", s[i]);
            puts("");
        }
    }
}