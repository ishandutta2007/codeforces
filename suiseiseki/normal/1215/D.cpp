#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define INF 2147483647
#define LLINF 9223372036854775807
#define LL long long
#define xyx AKIOI
#define Dilute AKIOI
#define Chtholly_Tree AKIOI
#define time_interspace AKIOI
#define memset0 AKIOI
#define Isonan AKIOI
#define Sooke AKIOI
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
int n,totl,totr,suml,sumr;
int main()
{
    n=read();
    for(int i=1;i<=n/2;i++){
        char c;cin>>c;
        if(c!='?')suml+=c-'0';else totl++;
    }
    for(int i=1;i<=n/2;i++){
        char c;cin>>c;
        if(c!='?')sumr+=c-'0';else totr++;
    }
    if(suml<sumr){
        int ans=sumr-suml,num=(totl-totr)/2;
        if(num*9==ans)printf("Bicarp");else printf("Monocarp");
    }
    if(sumr<suml){
        int ans=suml-sumr,num=(totr-totl)/2;
        if(num*9==ans)printf("Bicarp");else printf("Monocarp");
    }
    if(suml==sumr){
        if(totl!=totr)printf("Monocarp");else printf("Bicarp");
    }
    return 0;
}