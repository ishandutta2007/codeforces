#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int lou,x,y,n,k,ans,k3,k4,k5,cs,flag,gcd;
int e[10];

void egcd(int a,int b)
{
    if (b==0)
    {
        if (lou%a!=0) flag=-1;
        x=lou/a;
        y=1;
        gcd=a;
    }
    else
    {
        egcd(b,a%b);
        int e=y;
        y=x-(a/b)*y;
        x=e;
    }
}

void pan(int n3,int n4,int n5)
{
    if (n3>n4) return;
    if (n4>n5) return;
    int now=(abs(n3*e[3]-n4*e[4])+abs(n4*e[4]-n5*e[5]));
    if (now<ans)
    {
        ans=now;
        k3=n3;k4=n4;k5=n5;
    }
}

void doit(int n3,int k)
{
    int l4,r4,ck,left,right,mid,xx,yy,e5,e4;
    l4=n3;r4=k/(e[4]+e[5]);
    lou=k;
    flag=1;
    egcd(e[4],e[5]);
    if (flag==-1) return;
    //cout<<n3<<" "<<x<<" "<<y<<endl;
    e5=e[5]/gcd;
    e4=e[4]/gcd;
    x-=e5*1000000;
    y+=e4*1000000;
    ck=(l4-x-1)/e5+1;
    x+=ck*e5;
    y-=ck*e4;
    //cout<<n3<<" "<<x<<" "<<y<<" "<<e5<<" "<<e4<<" "<<endl;
    if (x>r4) return;
    pan(n3,x,y);
    left=1;right=(r4-x)/e5;
    while (left<=right)
    {
        mid=(left+right)/2;
        xx=x+mid*e5;
        yy=y-mid*e4;
        if (xx*e[4]<yy*e[5]) left=mid+1; else right=mid-1;
    }
    //cout<<right<<endl;
    x+=right*e5;
    y-=right*e4;
    //cout<<n3<<" "<<x<<" "<<y<<" "<<e5<<" "<<e4<<" "<<endl;
    pan(n3,x,y);
    x+=e5;
    y-=e4;
    //cout<<n3<<" "<<x<<" "<<y<<" "<<e5<<" "<<e4<<" "<<endl;
    pan(n3,x,y);
}

int main()
{
    //freopen("E.in","r",stdin);
    cin>>n>>k;
    memset(e,0,sizeof(e));
    for (int i=1;i<=n;i++)
    {
        cin>>cs;
        ++e[cs];
    }
    ans=maxlongint;
    k3=0;k4=0;k5=0;
    for (int i=0;i<=k/e[3];i++)
    {
        doit(i,k-i*e[3]);
    }
    if (ans==maxlongint) cout<<-1<<endl; else cout<<k3<<" "<<k4<<" "<<k5<<endl;

    return 0;
}