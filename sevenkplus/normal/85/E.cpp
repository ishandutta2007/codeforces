#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 5555
#define P 1000000007
int x[N],y[N],v[N],n,L,R,M,S;
void ff(int p,int c)
{
    v[p]=c;
    for(int i=0;i<n;i++)
        if(abs(x[i]-x[p])+abs(y[i]-y[p])>M)
            if(!v[i])ff(i,3-c);else
            if(v[i]==c)throw 0;
}
bool can()
{
    memset(v,0,sizeof v);S=1;
    for(int i=0;i<n;i++)
        if(!v[i])try{S=S*2%P;ff(i,1);}catch(...){return 0;}
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    for(L=0,R=10000;L<=R;)
    {
        M=(L+R)/2;
        if(can())R=M-1;else L=M+1;
    }
    M=L;can();
    printf("%d\n%d\n",M,S);
    return 0;
}