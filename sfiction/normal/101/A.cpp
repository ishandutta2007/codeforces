/*
ID: Sfiction
OJ: CF
PROB: 101A
*/
#include <cstdio>
const int MAXN=100000+10;

char s[MAXN];
int num[26];

int main(){
    int i,j,k,n;
    int min;
    gets(s);
    scanf("%d",&k);
    for (i=0;s[i];++i)
        ++num[s[i]-97];
    for (n=i=0;i<26;++i)
        n+=num[i]>0;
    while (k){
        for (min=0;num[min]==0;++min);
        for (j=min+1;j<26;++j)
            if (num[j]>0&&num[min]>num[j])
                min=j;
        if (k<num[min]) break;
        k-=num[min];
        num[min]=0;
        --n;
    }
    printf("%d\n",n);
    for (i=0;s[i];++i)
        if (num[s[i]-97])
            putchar(s[i]);
    return 0;
}