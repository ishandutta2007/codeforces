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

vector<int> a[1000],b[4];
int n,cs,ans,ct,hash[1000];

int doit(int e)
{
    //cout<<e<<" ffff"<<endl;
    int o,time,flag,ff,u;
    o=0;
    memset(hash,0,sizeof(hash));
    time=n;
    while (o!=n)
    {
        flag=true;
        while (flag)
        {
            flag=false;
            for (int ii=0;ii<b[e].size();ii++)
            {
                int i=b[e][ii];
                if (hash[i]==1) continue;
                ff=1;
                for (int j=0;j<a[i].size();j++)
                    if (hash[a[i][j]]==0)
                    {
                        ff=0;
                        break;
                    }
                if (ff==1) {flag=true;u=i;break;}
            }
            if (flag==false) break;
            hash[u]=1;
            o++;
        }
        if (o==n) break;
        e++;
        time++;
        if (e==4) e=1;
    }
    return time;
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>cs,b[cs].p_b(i);
    for (int i=1;i<=n;i++)
    {
        cin>>cs;
        for (int j=1;j<=cs;j++) cin>>ct,a[i].p_b(ct);
    }
    ans=min(min(doit(1),doit(2)),doit(3));
    cout<<ans<<endl;

    return 0;
}