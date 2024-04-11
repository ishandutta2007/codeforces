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

LL cs;
int n,tt,ct,lc,rc,hash[10],u[10],v[10],w[10];

bool cross(int x1,int y1,int x2,int y2)
{
    if ((x1>=x2)&&(x1<=y2)) return true;
    if ((y1>=x2)&&(y1<=y2)) return true;
    if ((x2>=x1)&&(x2<=y1)) return true;
    if ((y2>=x1)&&(y2<=y1)) return true;
    return false;
}

int main()
{
    u[1]=1;v[1]=3;w[1]=0;
    u[2]=4;v[2]=15;w[2]=1;
    u[3]=16;v[3]=81;w[3]=2;
    u[4]=82;v[4]=6723;w[4]=0;
    u[5]=6724;v[5]=50625;w[5]=3;
    u[6]=50626;v[6]=899999;w[6]=1;

    scanf("%d",&n);
    tt=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&cs);
        if (cs<=899999)
        {
            ct=0;
            for (int j=1;j<=6;j++) if ((cs>=u[j])&&(cs<=v[j])) ct=w[j];
        }
        else
        {
            memset(hash,0,sizeof(hash));
            lc=ceil(sqrt(sqrt(cs)));
            rc=floor(sqrt(cs));
            for (int j=1;j<=6;j++)
            {
                if (cross(lc,rc,u[j],v[j])) hash[w[j]]=1;
            }
            for (int j=0;j<=5;j++)
                if (hash[j]==0)
                {
                    ct=j;
                    break;
                }
        }
        tt^=ct;
    }
    if (tt==0) cout<<"Rublo"<<endl; else cout<<"Furlo"<<endl;
    return 0;
}