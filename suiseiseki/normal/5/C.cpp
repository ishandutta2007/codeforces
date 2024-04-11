#include <cstdio>
char s[1000005];
int st_i[1000005];
bool ok[1000005];
int main(){
    scanf("%s",s+1);
    int len=0;
    while(s[++len]!='\0');
    len--;
    int top=0;
    for(int i=1;i<=len;i++){
        if(s[i]==')'){
            if(top>0){
                ok[st_i[top]]=1;
                ok[i]=1;
                top--;
            }
        }
        else{
            top++;
            st_i[top]=i;
        }
    }
    int ans_len=0,ans_num=0;
    int now_len=0;
    for(int i=1;i<=len+1;i++){
        if(ok[i]){
            now_len++;
        }
        else{
            if(now_len>ans_len){
                ans_len=now_len;
                ans_num=1;
            }
            else if(now_len==ans_len){
                ans_num++;
            }
            now_len=0;
        }
    }
    if(ans_len==0){
        puts("0 1");
        return 0;
    }
    printf("%d %d\n",ans_len,ans_num);
    return 0;
}