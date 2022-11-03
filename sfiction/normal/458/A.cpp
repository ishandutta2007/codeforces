/*
ID: Sfiction
OJ: CF
PROB: 457A
*/
#include <cstdio>
#include <cstring>

const int MAXN=100000+10;

char s[MAXN];

int a[MAXN],b[MAXN];
int lena,lenb;

void Init(char s[],int f[],int &len){
    int i,j;
    scanf("%s",s);
    len=strlen(s)-1;
    for (i=0;i<=len;++i)
        f[len-i]=s[i]-48;
    for (i=len-1;i>=0;--i)
        for (j=i;f[j]==1 && f[j+1]==1;j+=2){
            f[j]=f[j+1]=0;
            f[j+2]=1;
        }
    for (len=len+1;len>=0 && f[len]==0;--len);
}

int Check(){
    int i;
    if (lena!=lenb)
        return lena<lenb ? -1 : 1;
    for (i=lena;i>=0;--i)
        if (a[i]!=b[i])
            break;
    if (i<0)
        return 0;
    return a[i]<b[i] ? -1 : 1;
}

int main(){
    int t;

    Init(s,a,lena);
    Init(s,b,lenb);

    t=Check();
    if (t==0)
        printf("=");
    else
        printf(t==-1 ? "<" : ">");
    return 0;
}