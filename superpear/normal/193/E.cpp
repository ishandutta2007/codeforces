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
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

struct matrix
{
    LL a1,a2,b1,b2;
} e,f[14][65];

LL pow10[15];
LL V,t;

LL cheng(LL a,LL b,LL bigp)
{
    LL ans=0,e=a;
    while (b>0)
    {
        if (b%2==1) ans=(ans+e)%bigp;
        b/=2;
        e=(e*2)%bigp;
    }
    return ans;
}

matrix cheng(matrix a,matrix b,LL bigp)
{
    matrix c;
    c.a1=(cheng(a.a1,b.a1,bigp)+cheng(a.a2,b.b1,bigp))%bigp;
    c.a2=(cheng(a.a1,b.a2,bigp)+cheng(a.a2,b.b2,bigp))%bigp;
    c.b1=(cheng(a.b1,b.a1,bigp)+cheng(a.b2,b.b1,bigp))%bigp;
    c.b2=(cheng(a.b1,b.a2,bigp)+cheng(a.b2,b.b2,bigp))%bigp;
    return c;
}

LL getwhich(LL place,LL bigpbase)
{
    LL bigp=pow10[bigpbase];
    LL k1=0,k2=1,k3,k4,o=0;
    while (place>0)
    {
        if (place%2==1)
        {
            k3=cheng(k1,f[bigpbase][o].a1,bigp)+cheng(k2,f[bigpbase][o].a2,bigp);
            k4=cheng(k1,f[bigpbase][o].b1,bigp)+cheng(k2,f[bigpbase][o].b2,bigp);
            k1=k3%bigp,k2=k4%bigp;
        }
        place/=2;
        ++o;
    }
    return k1;
}

int main()
{
    //freopen("E.in","r",stdin);
    pow10[0]=1;
    for (int i=1;i<=13;i++)
        pow10[i]=(LL)pow10[i-1]*10;
    cin>>V;
    if (V==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=1;i<=13;i++)
    {
        e.a1=0,e.a2=1,e.b1=1,e.b2=1;
        f[i][0]=e;
        for (int j=1;j<=60;j++) f[i][j]=cheng(f[i][j-1],f[i][j-1],pow10[i]);
    }
    vector<LL> ans,ans1;
    for (int i=0;i<15000;i++)
        if (getwhich(i,4)==V%10000) ans.p_b(i);
    for (int i=5;i<=13;i++)
    {
        ans1.clear();
        for (int j=0;j<ans.size();j++)
            for (int k=0;k<=9;k++)
            {
                t=(LL)pow10[i-1]*k+(LL)pow10[i-1]/2*k+ans[j];
                if (getwhich(t,i)==V%pow10[i]) ans1.p_b(t);
            }
        //cout<<ans[0]<<endl;
        ans.clear();
        for (int j=0;j<ans1.size();j++) ans.p_b(ans1[j]);
    }
    if (ans.empty()) cout<<"-1"<<endl; else
    {
        sort(ans.begin(),ans.end());
        cout<<*ans.begin()<<endl;
    }

    return 0;
}