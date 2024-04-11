#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
char s[100];
LL n,len=0;
int main() { 
    scanf("%s",s); 

    LL ans=0;
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]=='9') {
            ans+=9; s[i]='\0';
        } else {
            break;
        }
    }

    for(int i=0;s[i];i++) ans=ans+s[i]-'0';

    len=strlen(s); 
    if(len>=1)ans = ans + (len-1)*9;
    cout<<ans<<endl;
}