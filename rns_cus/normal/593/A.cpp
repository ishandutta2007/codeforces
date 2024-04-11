#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[101][1001];

int n;

int main(){
    ///freopen("2.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    int ans = 0;
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++)if(i!=j){
            int tp = 0;
            for(int k=0;k<n;k++){
                int r;
                for(r=0;s[k][r];r++) if(s[k][r]!='a'+i&&s[k][r]!='a'+j) break;
                if(r==strlen(s[k])) tp+=strlen(s[k]);
            }
            ans = max(ans,tp);
        }
    }
    printf("%d\n",ans);
}