#include<bits/stdc++.h>
using namespace std;
int T,n; char str[3010];
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%s",&n,str+1);
        while (n>=1 && !((str[n]-'0')&1)) n--;
        if (!n){
            puts("-1");
        }else{
            int s=0;
            for (int i=1; i<=n; i++) s+=str[i]-'0';
            if (s&1){
                int p=0;
                for (int i=1; i<n; i++) if ((str[i]-'0')&1){
                    p=i;
                    break;
                }
                if (p){
                    if (p==1){
                        p++;
                        while (str[p]=='0') p++;
                        for (int i=p; i<=n; i++) printf("%c",str[i]);
                        puts("");
                    }else{
                        for (int i=1; i<=n; i++) if (i!=p) printf("%c",str[i]);
                        puts("");
                    }
                }else{
                    puts("-1");
                }
            }else{
                for (int i=1; i<=n; i++) printf("%c",str[i]);
                puts("");
            }
        }
    }
}