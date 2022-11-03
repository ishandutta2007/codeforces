/*
ID: Sfiction
OJ: CF
PROB: 101A
*/
#include <cstdio>
const int MAXN=100000+10;

char s[MAXN];

int main(){
    int i,n;
    int ans;
    gets(s);
    if (s[1]==0){
        printf("0");
        return 0;
    }
    for (n=i=0;s[i];++i)
        n+=s[i]-48;
    for (ans=1;n>=10;++ans){
        for (i=0;n;n/=10)
            i+=n%10;
        n=i;
    }
    printf("%d",ans);
    return 0;
}