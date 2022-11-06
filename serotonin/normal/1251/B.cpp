#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

char s[55];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,zer=0,one=0,odd=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%s", s);
            int len=strlen(s);
            if(len&1) odd++;
            for(int j=0; s[j]; j++) {
                if(s[j]=='0') zer++;
                else one++;
            }
        }

        if(odd) printf("%d\n", n);
        else {
            if(zer&1) printf("%d\n", n-1);
            else printf("%d\n", n);
        }
    }
}