#include <cstdio>
char s[2005];
int main(){
    int n;
    scanf("%d\n",&n);
    int len;
    int hour,minute,l_h=25,l_min=61;
    int ans=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        len=0;
        while((s[len++]=getchar())!='\n');
        hour=minute=0;
        hour=(s[1]-'0')*10+(s[2]-'0');
        minute=(s[4]-'0')*10+(s[5]-'0');
        if(hour==12){
            hour=0;
        }
        if(s[7]=='p'){
            hour+=12;
        }
        if((hour<l_h)||(hour==l_h&&minute<l_min)){
            ans++;
        }
        if(hour==l_h&&minute==l_min){
            cnt++;
        }
        else{
            cnt=1;
        }
        if(cnt>10){
            ans++;
            cnt=1;
        }
        l_h=hour;
        l_min=minute;
    }
    printf("%d\n",ans);
    return 0;
}