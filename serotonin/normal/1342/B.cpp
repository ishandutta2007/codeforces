#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

char s[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%s", s);
        bool no = 0;
        for(int i=1; s[i]; i++) if(s[i]!=s[i-1]) no = 1;
        if(no) {
            for(int i=0; s[i]; i++) printf("01");
            puts("");
        }
        else printf("%s\n", s);
    }
}