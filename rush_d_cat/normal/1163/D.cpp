#include <iostream>
#include <cstring>
using namespace std;
const int N=1002;
char s[N],s1[N],s2[N];
int dp[N][52][52];
int nex1[52],nex2[52];
void build(char *s, int *nex){
    nex[0]=nex[1]=0;
    int j=0;
    for(int i=1;s[i];i++){
        while(j>0 && s[i]!=s[j]) j=nex[j];
        if(s[i]==s[j])j++;
        nex[i+1]=j;
    }
}
int main(){
    scanf("%s%s%s",s,s1,s2);
    build(s1,nex1), build(s2,nex2);
    int n=strlen(s),l1=strlen(s1),l2=strlen(s2);
    for(int i=0;i<=n;i++){
        for(int j=0;j<52;j++)for(int k=0;k<52;k++) dp[i][j][k]=-1e9;
    }
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=l1;j++){
            for(int k=0;k<=l2;k++){
                if(s[i]!='*'){
                    int p1=j;
                    while(p1>0 && s[i]!=s1[p1]) p1=nex1[p1];
                    if(s[i]==s1[p1])p1++;

                    int p2=k;
                    while(p2>0 && s[i]!=s2[p2]) p2=nex2[p2];
                    if(s[i]==s2[p2])p2++;

                    int add=0;
                    if(p1==l1)add++;
                    if(p2==l2)add--;
                    dp[i+1][p1][p2]=max(dp[i][j][k]+add, dp[i+1][p1][p2]);
                } else {
                    for(char c='a';c<='z';c++){
                        int p1=j;
                        while(p1>0 && c!=s1[p1]) p1=nex1[p1];
                        if(c==s1[p1])p1++;

                        int p2=k;
                        while(p2>0 && c!=s2[p2]) p2=nex2[p2];
                        if(c==s2[p2])p2++;
                        
                        int add=0;
                        if(p1==l1)add++;
                        if(p2==l2)add--;
                        dp[i+1][p1][p2]=max(dp[i][j][k]+add, dp[i+1][p1][p2]);   
                    }                 
                }
            }
        }
    }
    int ans=-1e9;
    for(int j=0;j<=l1;j++)for(int k=0;k<=l2;k++)if(dp[n][j][k]>=ans)ans=dp[n][j][k];
    cout<<ans<<endl;
}