#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map> 
using namespace std;
#define re register int
inline int read(){
    int x=0,ff=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*ff;
}
int main(){
    int tt=read(),n,s,t;
    while(tt--){
        n=read();s=read();t=read();
        printf("%d\n",1+max(n-s,n-t));
    }
    return 0;
}