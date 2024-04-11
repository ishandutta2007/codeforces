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

int n,o,flag,t;
int main()
{
    //freopen("B.in","r",stdin);
    scanf("%d",&n);
    string s,st[100],sc;
    for (int tt=1;tt<=n;tt++)
    {
        cin>>s;
        sc="";o=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]==':')
            {
                ++o;st[o]=sc;sc="";
            }
            else sc+=s[i];
        }
        ++o;st[o]=sc;
        flag=-1;
        if (o>8)
        {
            for (int i=1;i<=o;i++)
                if (st[i]=="")
                    for (int j=i;j<o;j++) st[j]=st[j+1];
            --o;
        }
        if (o!=8)
        {
            for (int i=1;i<=o;i++) if (st[i]=="") {flag=i;break;}
        }
        for (int i=1;i<=o;i++)
        {
            t=4-st[i].size();
            for (int j=1;j<=t;j++) st[i]='0'+st[i];
        }
        if (flag!=-1) for (int i=1;i<=8-o;i++) st[flag]+=":0000";
        for (int i=1;i<=o;i++)
        {
            if (i!=1) cout<<":";
            cout<<st[i];
        }
        cout<<endl;
    }
    return 0;
}