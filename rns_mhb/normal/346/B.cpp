#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define M 102
#define inf 2000000
char s1[M],s2[M],pat[M];
int pre[M],pp[M][30];
int res[M][M][M],inv[M][M][M];

int main() {
//  freopen("b.in","r",stdin);
    int l1,l2,lp,i,j,k;
    scanf("%s %s %s",s1,s2,pat);
    l1=strlen(s1);
    l2=strlen(s2);
    lp=strlen(pat);
    for(i=lp;i;i--) pat[i]=pat[i-1];
    pre[1]=k=0;
    for(i=2;i<=lp;i++) {
        while(k && pat[i]!=pat[k+1]) k=pre[k];
        if(pat[i]==pat[k+1]) k++;
        pre[i]=k;
    }
    for(i=0;i<lp;i++) {
        for(j=0;j<26;j++) {
            k=i;
            while(k && pat[k+1]-'A'!=j) k=pre[k];
            if(pat[k+1]-'A'==j) k++;
            pp[i][j]=k;
        }
    }
    memset(res,-1,sizeof(res));
    res[0][0][0]=0;
    for(i=0;i<=l1;i++) {
        for(j=0;j<=l2;j++) {
            if(i+j==l1+l2) continue;
            for(k=0;k<lp;k++) {
                if(res[i][j][k]<0) continue;
                int m=res[i][j][k];
                if(i<l1 && res[i+1][j][k]<m) {
                    res[i+1][j][k]=m;
                    inv[i+1][j][k]=i*M*M+j*M+k;
                }
                if(j<l2 && res[i][j+1][k]<m) {
                    res[i][j+1][k]=m;
                    inv[i][j+1][k]=i*M*M+j*M+k;
                }
                if(i<l1 && j<l2 && res[i+1][j+1][k]<m) {
                    res[i+1][j+1][k]=m;
                    inv[i+1][j+1][k]=i*M*M+j*M+k;
                }
                if(i<l1 && j<l2 && s1[i]==s2[j]) {
                    int kk=pp[k][s1[i]-'A'];
                    if(kk==lp) continue;
                    if(res[i+1][j+1][kk]<m+1)  {
                        res[i+1][j+1][kk]=m+1;
                        inv[i+1][j+1][kk]=i*M*M+j*M+k+inf;
                    }
                }
            }
        }
    }
    int mx=-1;
    for(i=0;i<lp;i++) if(mx<res[l1][l2][i]) {
        mx=res[l1][l2][i];
        k=i;
    }
    if(mx<1) {
        puts("0");
        return 0;
    }
    char sto[M];
    int tt=0;
    int a=l1,b=l2,c=k;
    while(res[a][b][c]) {
        if(inv[a][b][c]>=inf) {
            inv[a][b][c]-=inf;
            sto[tt++]=s1[a-1];
        }
        k=inv[a][b][c];
        a=k/M/M;
        b=k/M%M;
        c=k%M;
    }
    sto[tt]=0;
    reverse(sto,sto+tt);
    puts(sto);
    return 0;
}