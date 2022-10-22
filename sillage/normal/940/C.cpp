#include<cstdio>
#include<cstring>
char s[100100];
int b[100100],t;
int n,k,vis[30],lis[30],pls[30];
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int len=strlen(s);
    for (int i=0; i<len; i++) vis[s[i]-'a']=1;
    for (int i=0; i<26; i++) if (vis[i]) pls[i]=t,lis[t++]=i;
    if (k>n){
        printf("%s",s);
        for (int i=n+1; i<=k; i++) printf("%c",lis[0]+'a');
        return 0;
    }
    for (int i=0; i<k; i++) b[i]=pls[s[i]-'a'];
    b[k-1]++;
    for (int i=k-1; i>=1; i--){
        if (b[i]>=t){
            b[i]-=t;
            b[i-1]++;
        }
    }
    for (int i=0; i<k; i++)  printf("%c",lis[b[i]]+'a');
    return 0;
}