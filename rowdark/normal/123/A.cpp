#include<stdio.h>
#include<cstring>
bool isprime[1001];
long cc[26];
long i,j,k,l,n,m;
char S[1002];
int main(){
    scanf("%s",S+1);
    l=strlen(S+1);
    for(i=2;i<=l;++i)
        if(!isprime[i])
            for(j=i+i;j<=l;j+=i)
                isprime[j]=1;
    for(k=1,i=2;i<=l;++i)
        if(l<2*i&&!isprime[i])
            ++k;
    for(i=1;i<=l;++i) ++cc[S[i]-'a'];
    n=0;
    for(i=1;i<26;++i) if(cc[n]<cc[i]) n=i;
    if(cc[n]<l-k){
        printf("NO\n");
        goto end;
        }
    printf("YES\n");
    memset(S,0,sizeof(S));
    for(i=2;i<=l;++i) if(i*2<=l||isprime[i]) --cc[n],S[i]=n+'a';
    for(j=0,i=1;i<=l;++i)
        if(!S[i]){
            while(cc[j]==0) ++j;
            S[i]=j+'a',--cc[j];
            }
    printf("%s\n",S+1);
    end:
    scanf("%s",S+1);
    return 0;
}