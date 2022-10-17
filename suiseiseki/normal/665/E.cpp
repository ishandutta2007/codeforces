#include <iostream>
#include <cstdio>
using namespace std;
const int X=2147483647;
const int N=1e6+5;
const int L=30;
int n,k;
int t[30*N][2],cnt;
int a[30*N];
int work(int s)
{
    int v,sum=0,p=k,q=s,i;
    v=1;
    for(i=0;i<=L;i++){
        if(!v)break;
        if(p>>L){
            v=t[v][1^(q>>L)];
        }
        else{
            sum+=a[t[v][1^(q>>L)]];
            v=t[v][q>>L];
        }
        p=(p<<1)&X;
        q=(q<<1)&X;
    }
    v=1;
    ++a[v];
    for(i=0;i<=L;i++){
        if(t[v][s>>L])v=t[v][s>>L];
        else ++cnt,t[v][s>>L]=cnt,v=cnt;
        s=(s<<1)&X;
        ++a[v];
    }
    return sum;
}
int main()
{
    int i,p,s=0;
    scanf("%d%d",&n,&k);
    cnt=1;
    k=k-1;
    long long ans=work(s);
    for(i=1;i<=n;i++){
        scanf("%d",&p);
        s=s^p;
        ans+=work(s);
    }
    cout<<ans<<endl;
    return 0;
}