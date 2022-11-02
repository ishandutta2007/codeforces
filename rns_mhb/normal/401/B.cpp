#include<stdio.h>
#include<algorithm>
#include<string.h>
#define M 4001
using namespace std;
int a[M];
int maxx,minn;
void process(int x){
    x-=1;
    maxx+=x;
    minn+=x/2+x%2;
}
int main(){
    int i,x,k,t,p;
    char s[6];
   // freopen("in.txt","r",stdin);
    scanf("%d %d\n",&x,&k);
    if(k==0){process(x);goto k;}
    maxx=minn=0;
    for(i=0,t=0;i<k;i++){
            scanf("%d",&p);
            if(p==1)scanf("%d",&a[t++]),scanf("%d",&a[t++]);
            if(p==2)scanf("%d",&a[t++]);
    }
    sort(a,a+t);
    for(i=0;i<t-1;i++)if(a[i+1]-a[i]!=1)process(a[i+1]-a[i]);
    if(a[0]-0!=1)process(a[0]-0);
    if(x-a[t-1]!=1)process(x-a[t-1]);
    k:;//{process(x);}
    printf("%d %d\n",minn,maxx);
    return 0;
}