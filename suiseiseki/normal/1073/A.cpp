#include <cstdio>
#include <cstring>
int words[30];
char s[1005];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    for(int i=1;i<=n;i++){
        memset(words,0,sizeof words);
        words[(int)(s[i]-'a')]++;
        for(int j=i+1,k;j<=n;j++){
            words[(int)(s[j]-'a')]++;
            for(k=0;k<26;k++){
                if((words[k]<<1)>(j-i+1)){
                    break;
                }
            }
            if(k==26){
                puts("YES");
                for(int l=i;l<=j;l++){
                    putchar(s[l]);
                }
                puts("");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}