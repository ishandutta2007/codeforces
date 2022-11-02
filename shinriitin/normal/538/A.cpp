#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=105;

char a[MAXN],b[15]={' ','C','O','D','E','F','O','R','C','E','S'};

int n,m=10;

char c[MAXN];

inline bool check(char*a,int l){
    if(l!=m)return 0;
    for(int i=1;i<=l;++i)
        if(a[i]!=b[i])return 0;
    return 1;
}

int main(){
    scanf("%s",a+1),n=strlen(a+1);
    if(n<m)return puts("No"),0;
    for(int l=1;l<=n;++l){
            int r=l+n-m-1;
            int j=0;
            for(int i=1;i<=n;++i)
                if(i>=l&&i<=r){}
                else c[++j]=a[i];
            if(check(c,j))return puts("Yes"),0;
        }   
    return puts("No"),0;
}