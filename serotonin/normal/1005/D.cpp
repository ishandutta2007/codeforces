#include<stdio.h>
#include<string.h>
#include<math.h>

char s[200005];

int main()
{
    scanf("%s", s);
    int l,i,j,x=0,y=0,ans=0;
    l=strlen(s);
    for(i=0;i<l;i++) {
        if(s[i]=='3' || s[i]=='6' || s[i]=='9') s[i]='0';
        if(s[i]=='2' || s[i]=='5' || s[i]=='8') s[i]='2';
        if(s[i]=='1' || s[i]=='4' || s[i]=='7') s[i]='1';
    }

    for(i=0;i<l;i++) {
        if(s[i]=='0') {
            ans++;
            continue;
        }
        if(s[i]!=s[i+1] && s[i+1]!='0' && i+1<l) {
            ans++;
            i++;
            x++;
            continue;
        }
        if(s[i]==s[i+1] && s[i]==s[i+2] && s[i+1]!='0' && s[i+2]!='0' && i+2<l) {
            ans++;
            i+=2;
            y++;
            continue;
        }
    }

    printf("%d\n", ans);

}