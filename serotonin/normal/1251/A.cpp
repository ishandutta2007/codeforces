#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        char s[505];
        scanf("%s", s);
        int d[30]={0};
        for(int i=0, j=1; s[i]; i++, j++) {
            if(s[i]!=s[i+1]) {
                if(j&1) {
                    d[s[i]-'a']=1;
                }
                j=0;
            }
        }
        for(int i=0; i<30; i++) {
            if(d[i]) printf("%c", 'a'+i);
        }
        puts("");
    }
}