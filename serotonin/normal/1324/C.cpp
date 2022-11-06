#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

char s[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int ans=0, l=-1;
        scanf("%s", s);
        for(int i=0; ; i++) {
            if(s[i]!='L') {
                ans=max(i-l, ans);
                l=i;
                if(!s[i]) break;
            }
        }
        printf("%d\n", ans);
    }
}