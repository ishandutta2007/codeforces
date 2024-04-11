#include <iostream>
#include <cstring>
using namespace std;
const int N=500000+10;
char s[N]; int n;
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    int lef=-1,rig=-1;

    int state=0;
    for(int i=1;i<=n;i++){
        if(state==0 && s[i]=='[') state=1;
        if(state==1 && s[i]==':') state=2;
        if(state==2) {
            lef=i; break;
        }
    }
    state=0;
    for(int i=n;i>=1;i--){
        if(state==0 && s[i]==']') state=1;
        if(state==1 && s[i]==':') state=2;
        if(state==2) {
            rig=i; break;
        }        
    }

    int cnt=0;
    for(int i=lef;i<=rig;i++)
        if(s[i]=='|')cnt++;
    if(lef>=rig) return !printf("-1\n");
    if(lef!=-1 && rig!=-1)
        printf("%d\n", 4+cnt);
    else
        printf("-1\n");
}