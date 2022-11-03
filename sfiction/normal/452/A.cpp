/*
ID: Sfiction
OJ: CF
PROB: 452A
*/
#include <cstdio>
#include <cstring>

const int MAXN=8;
const char name[8][10]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(){
    char s[10];
    int i,j,n;
    scanf("%d",&n);
    scanf("%s",s);
    for (i=0;i<MAXN;++i)
        if (strlen(name[i])==n){
            for (j=0;j<n;++j)
                if (s[j]!='.' && s[j]!=name[i][j])
                    break;
            if (j==n)
                printf("%s",name[i]);
        }
    return 0;
}