#include<bits/stdc++.h>
using namespace std;

const int sz=2e5;

char s[sz];
int t[30];

int main ()
{
    int i,n,f=0;
    memset(t, 0, sizeof t);

    scanf("%d %s", &n, s);
    for(i=0;i<n;i++) {
        int x=s[i]-'a';
        t[x]++;
    }

    for(i=0;i<='z'-'a';i++) {
        if(t[i]>1) {
            f=1;
        }
    }

    if(f==1 || n==1) puts("Yes");
    else puts("No");
}