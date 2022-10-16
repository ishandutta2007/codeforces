#include<cstdio>
int f[3011][3011],y=998244353,r,i,j;char s[3011],t[3011];
int main(){
    scanf("%s%s",s+1,t+1);
    for(i=1;s[i];++i)f[i][i]=(!t[i]||s[1]==t[i])*2;
    for(int l=2;s[l];++l)for(i=1;s[j=i+l-1];++i)
            f[i][j]=(f[i+1][j]*(!t[i]||s[l]==t[i])+f[i][j-1]*((!t[j]||s[l]==t[j])))%y;
    for(i=1;s[i];++i)(r+=f[1][i]*!t[i+1])%=y;
    printf("%d",r);
    return 0;
}