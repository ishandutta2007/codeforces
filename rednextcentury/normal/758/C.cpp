#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long loop;
long long numloop;
long long fl;
long long mid;
long long n,m,k,x,y;
int a[200][200];
void precalc(long long rem)
{
    int cur=1,dx=1,dy=1,X=1,Y=1;
    while(rem)
    {
        rem--;
        if (Y>m)Y=1,X+=dx;
        if (X>n)X=n-1,dx=-1;
        if (X<1)X=2,dx=1;
        a[X][Y]++;
        Y+=dy;
    }
}
long long calc(long long X,long long Y)
{
    if (X==1 || X==n)
        return fl+a[X][Y];
    else
        return mid+a[X][Y];
}
int main()
{
    fast_io
    cin>>n>>m>>k>>x>>y;
    if (n==1)
    {
        long long mn=k/m;
        long long mx=k/m+(k%m>0);
        long long sergey=(y>k%m)?mn:mx;
        cout<<mx<<' '<<mn<<' '<<sergey<<endl;
    }
    else
    {
        loop=2*n-2;
        loop=loop*m;
        numloop=k/loop;
        fl=numloop;
        mid=numloop*2;
        long long rem=k%loop;
        precalc(rem);
        long long mn=min(calc(1,m),calc(n,m));
        long long mx=max(max(calc(1,1),calc(2,1)),max(calc(n,1),calc(n-1,1)));
        long long sergey=calc(x,y);
        cout<<mx<<' '<<mn<<' '<<sergey<<endl;
    }
}