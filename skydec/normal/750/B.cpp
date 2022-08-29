#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
    int S=20000;
    int n;scanf("%d",&n);
    int now=0;
    while(n--){
        int d;char str[10];
        scanf("%d",&d);
        scanf("%s",str+1);
        int ty=0;
        if(str[1]=='S')ty=1;
        else if(str[1]=='N')ty=2;
        else ty=3;

        if(now==0&&ty!=1){
            puts("NO");
            return 0;
        }
        if(now==S&&ty!=2){
            puts("NO");
            return 0;
        }
        if(ty==2)now-=d;
        else if(ty==1)now+=d;

        if(!(now>=0&&now<=S)){
            puts("NO");
            return 0;
        }
    }
    if(now!=0)puts("NO");else puts("YES");
    return 0;
}