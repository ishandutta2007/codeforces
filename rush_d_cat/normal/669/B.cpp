#include<iostream>
#include<stdio.h>
using namespace std;
typedef __int64 ll;
const ll MAX=1e5+2;
bool used[MAX];
char dir[MAX];
ll dis[MAX];
int main(){
    int n;cin>>n;
    scanf("%s",dir);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&dis[i]);
        used[i]=false;
        if(dir[i-1]=='<') dis[i]*=-1;
    }
    bool ok=true;
    int tmp=1;
    while(true){
        used[tmp]=true;
        tmp+=dis[tmp];
        if(tmp<1||tmp>n){ok=false;break;}
        if(used[tmp]) break;
    }
    if(ok) cout<<"INFINITE"<<endl;
    else cout<<"FINITE"<<endl;
    return 0;
}