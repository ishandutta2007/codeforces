#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=4e5,INF=1e17;

char s[sz];

int main()
{
    int i,j,k,l,L,t,candy=0,snow=0;
    scanf("%s %d", s, &k);
    L=strlen(s);
    for(i=0; i<L; i++) {
        if(s[i]=='*') snow++;
        else if(s[i]=='?') candy++;
    }
    if(snow) {
        l=L-snow-candy;
        if(l-(snow+candy-1)<=k) {
            int f=1;
            for(i=0; i<L; i++) {
                if(s[i+1]=='?' || s[i+1]=='*') {
                    if(f && s[i+1]=='*') {
                        for(j=0; j<=k-l+(snow+candy-1); j++) printf("%c", s[i]);
                        f=0;
                        i++;
                    }
                    else {
                        i++;
                        continue;
                    }
                }
                else printf("%c", s[i]);
            }
        }
        else if(l-(snow+candy)==k) {
            for(i=0; i<L; i++) {
                if(s[i+1]=='?' || s[i+1]=='*') i++;
                else printf("%c", s[i]);
            }
        }
        else puts("Impossible");
    }
    else {
        l=L-candy;
        if(l>=k && l-candy<=k) {
            int f=l-k;
            for(i=0; i<L; i++) {
                if(s[i+1]=='?') {
                    if(f) {
                        i++;
                        f--;
                    }
                    else {
                        printf("%c", s[i]);
                        i++;
                    }
                }
                else printf("%c", s[i]);
            }
        }
        else puts("Impossible");
    }
}