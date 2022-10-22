#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return f==-1?~x+1:x;
}
int main(){
    int T=read();
    while(T--){
        int c=read(),d=read();
        if(abs(c-d)&1){
            printf("-1\n");continue ;
        }
        if(c==d&&c==0) printf("0\n");
        else if(c==d) printf("1\n");
        else printf("2\n");
    }
}