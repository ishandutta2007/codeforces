#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 5002;

int dp[N][N],k,GG[N]; 
char s[N],ans[N];
vector<int> pos[N];int head[N];

int main(){
    scanf("%s%d", s+1, &k); 
    int n=strlen(s+1);

    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i][1]=1;
        if(s[i]!=s[i+1]) dp[i][1]=0;
    }
    
    for(int k=2;k<=n;k++){
        for(int i=1;i+k<=n;i++){
            if(k%2==0) {
                if(s[i]==s[i+k] && (k-4<0||dp[i+2][k-4])) dp[i][k]=1;
            } else {
                if(s[i]==s[i+k] && (k-4<0||dp[i+2][k-4])) dp[i][k]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            if(dp[i][j]==1) {
                //printf("ok %d %d\n", i,i+j);
                pos[i].push_back(i+j);
            }
        }
    }
    int has=0;
    for(int i=0;i<n;i++){
        if(has>=k) break;
        int cntA=0,buA=0;
        for(int j=1;j+i<=n;j++){
            if(GG[j] == 0 && s[j+i] == 'a') {
                //printf("j=%d, j+i=%d\n", j,j+i);
                cntA += pos[j].size() - head[j]; if(dp[j][i]) buA++;
            } 
        }

        int cntB=0,buB=0;
        for(int j=1;j+i<=n;j++){
            if(GG[j] == 0 && s[j+i] == 'b') {
                cntB += pos[j].size() - head[j]; if(dp[j][i]) buB++;
            }
        }
        //printf("i=%d, cntA=%d,buA=%d,cntB=%d,buB=%d\n", i,cntA,buA,cntB,buB);
        if(has+cntA>=k) {
            has+=buA;
            ans[i]='a';
        } else {
            has+=cntA+buB;
            ans[i]='b';
        }
        //printf("%c %d\n", ans[i], has);
        for(int j=1;j+i<=n;j++){
            if(GG[j]==0 && s[j+i]==ans[i]){
            }
            else GG[j]=1; 
            while(head[j]<pos[j].size() && pos[j][head[j]]<=j+i) head[j]++;
        }

    }
    printf("%s\n", ans);
}