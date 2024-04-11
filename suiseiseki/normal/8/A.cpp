#include<cstdio>
#include<cstring>
const char *str[4]={"fantasy","forward","backward","both"};
char s[100002],s1[102],s2[102];
int main() {
    int p=-1;
    bool t=0,flag1=0,flag2=0;
    scanf("%s%s%s",s,s1,s2);
    for(int i=0;s[i]&&p==-1;++i){
        t=1;
        for(int j=0;s1[j]&&t;++j){
            if(s[i+j]!=s1[j]){
                t=0;
            }
        }
        if(t){
            p=i+strlen(s1);
        }
    }
    if(p!=-1){
        for(int i=p;s[i]&&!flag1;++i){
            flag1=1;
            for(int j=0;s2[j]&&flag1;++j){
                if(s[i+j]!=s2[j]){
                    flag1=0;
                }
            }
        }
    }
    p=-1;
    for(int i=strlen(s)-1;i>=0&&p==-1;--i){
        t=1;
        for(int j=0;s1[j]&&t;++j){
            if(s[i-j]!=s1[j])
                t=0;
        }
        if(t){
            p=i-strlen(s1);
        }
    }
    if(p!=-1){
        for(int i=p;i>=0&&!flag2;--i){
            flag2=1;
            for(int j=0;s2[j]&&flag2;++j){
                if(s[i-j]!=s2[j]){
                    flag2=0;
                }
            }
        }
    }
    puts(str[flag1+flag2*2]);
    return 0;//
}