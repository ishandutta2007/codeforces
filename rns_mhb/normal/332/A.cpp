#include <stdio.h>
#include <string.h>
#include <string>

char s[3000];

int main(){
    //freopen("a.in","r",stdin);
    int i,j,k,n; scanf("%d\n",&n);

    scanf("%s",s);
    int sn=strlen(s);
    k=0;
    int ans=0;
    for(i=0;i<sn;i++){
        k=i%n;
        if(k==0){
            if(i<3)continue;
            for(j=i-3;j<i-1;j++)if(s[j]!=s[j+1])break;
            if(j==i-1)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}