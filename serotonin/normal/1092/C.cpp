#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5;

char a[205][105];
char p[2][105];
int len[205];
char ans[205],fin[205];

void swp()
{
    char s[105];
    strcpy(s, p[1]);
    strcpy(p[1], p[0]);
    strcpy(p[0], s);
}

int main()
{
    int n,i,j,k=0;
    cin >> n;
    for(i=0; i<2*n-2; i++) {
        scanf("%s", a[i]);
        len[i]=strlen(a[i]);
        if(len[i]==n-1) {
            strcpy(p[k++], a[i]);
        }
        fin[i]='a';
    }

    for(i=1; i<n-1; i++) {
        if(p[0][i]!=p[1][i-1]) break;
    }
    if(i<n-1) swp();

    rewnd: ;
    for(i=0; i<2*n-2; i++) {
        char c;
        for(j=0; j<len[i]; j++) {
            if(a[i][j]!=p[0][j]) {
                c='S'; break;
            }
            if(a[i][j]!=p[1][n-1-len[i]+j]) {
                c='P'; break;
            }
        }
        if(j==len[i]) {
            if(fin[len[i]]=='P') c='S';
            else c='P';
        }
        ans[i]=c;
        fin[len[i]]=c;
    }

    int x=0;
    for(i=0; i<2*n-2; i++) {
        if(ans[i]=='P') x++;
        fin[i]='a';
    }
    if(x!=n-1) {
        swp();
        goto rewnd;
    }

    for(i=0; i<2*n-2; i++) printf("%c", ans[i]);
    puts("");
}