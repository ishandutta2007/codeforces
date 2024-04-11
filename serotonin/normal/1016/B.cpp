#include <bits/stdc++.h>
using namespace std;
const int sz=2e5 + 5;

char s[sz],t[sz];
int w[sz];

main()
{
    int i,j,n,m,q,k,a,b;
    scanf("%d %d %d", &n, &m, &q);
    scanf("%s %s", s, t);
    if(n>=m) {
        memset(w,0,sizeof w);
        for(i=0;i<n-m+1;i++) {
            for(j=i;j<i+m;j++) {
                if(s[j]!=t[j-i]) break;
            }
            if(j==i+m) w[i]=1;
        }
        //for(i=0;i<n;i++) printf("%d", w[i]);
        //printf("\n\n\n");

        for(i=0;i<q;i++) {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            if(b-a+1>=m) {
                k=0;
                for(j=a;j<=b-m+1;j++) k+=w[j];
                printf("%d\n", k);
            }
            else puts("0");
        }
    }
    else {
        for(i=0;i<q;i++) {
            scanf("%d %d", &a, &b);
            puts("0");
        }
    }
}