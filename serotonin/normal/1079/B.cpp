#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5,m=1e9+7;

char s[105];
char ans[10][200];

int main()
{
    int n,i,j,k,x,y,z;
    cin >> s;
    n=strlen(s);
    int r=n/20;
    if(n%20) r++;
    int rem=r-(n%r);
    if(rem==r) rem=0;
    int c=(n+rem)/r;

    printf("%d %d\n", r, c);

    int crem=rem/r;
    for(i=0;i<crem;i++) {
        for(j=0;j<r;j++) {
            ans[j][i]='*';
        }
    }

    int finrem=rem%r;
    for(i=0;i<finrem;i++) {
        ans[i][crem]='*';
    }
    k=0;
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            if(ans[i][j]!='*') {
                ans[i][j]=s[k++];
            }
        }
    }
    for(i=0;i<r;i++) puts(ans[i]);
}