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

const int maxn=100005;

vector<int> cs,zhh[maxn];
vector<vector<int> > ans;
int n,tt,c;
int a[maxn],b[maxn],vis[maxn];

void pushk(int i,int len)
{
    cs.clear();
    for (int j=zhh[i].size()-len;j<=zhh[i].size()-1;j++) cs.p_b(b[zhh[i][j]]);
    cs.p_b(b[zhh[i][zhh[i].size()-1]]);
    for (int j=zhh[i].size()-len;j<zhh[i].size()-1;j++) cs.p_b(b[zhh[i][j]]);
    ans.p_b(cs);
    b[zhh[i][zhh[i].size()-1]]=b[zhh[i][zhh[i].size()-len]];
    zhh[i][zhh[i].size()-len]=zhh[i][zhh[i].size()-1];
    for (int j=1;j<=len-1;j++) zhh[i].erase(zhh[i].end()-1);
}

void pusht(int i1,int i2,int len1,int len2)
{
    cs.clear();
    for (int j=zhh[i1].size()-len1;j<=zhh[i1].size()-1;j++) cs.p_b(b[zhh[i1][j]]);
    for (int j=zhh[i2].size()-len2;j<=zhh[i2].size()-1;j++) cs.p_b(b[zhh[i2][j]]);
    cs.p_b(b[zhh[i1][zhh[i1].size()-1]]);
    for (int j=zhh[i1].size()-len1;j<zhh[i1].size()-1;j++) cs.p_b(b[zhh[i1][j]]);
    cs.p_b(b[zhh[i2][zhh[i2].size()-1]]);
    for (int j=zhh[i2].size()-len2;j<zhh[i2].size()-1;j++) cs.p_b(b[zhh[i2][j]]);
    ans.p_b(cs);
    b[zhh[i1][zhh[i1].size()-1]]=b[zhh[i1][zhh[i1].size()-len1]];
    zhh[i1][zhh[i1].size()-len1]=zhh[i1][zhh[i1].size()-1];
    for (int j=1;j<=len1-1;j++) zhh[i1].erase(zhh[i1].end()-1);
    b[zhh[i2][zhh[i2].size()-1]]=b[zhh[i2][zhh[i2].size()-len2]];
    zhh[i2][zhh[i2].size()-len2]=zhh[i2][zhh[i2].size()-1];
    for (int j=1;j<=len2-1;j++) zhh[i2].erase(zhh[i2].end()-1);
}

int main()
{
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]=i;
    memset(vis,0,sizeof(vis));
    tt=0;
    for (int i=1;i<=n;i++)
        if (vis[i]==0)
        {
            ++tt;
            c=a[i];
            vis[i]=1;
            while (c!=i)
            {
                vis[c]=1;
                zhh[tt].p_b(c);
                c=a[c];
            }
            zhh[tt].p_b(i);
        }
    for (int i=1;i<=tt;i++)
    {
        while (zhh[i].size()>=5) pushk(i,5);
        while (zhh[i].size()>=4) pushk(i,4);
    }
    vector<int> e1,e2;
    for (int i=1;i<=tt;i++)
    {
        if (zhh[i].size()==3) e1.p_b(i);
        if (zhh[i].size()==2) e2.p_b(i);
    }
    while ((e1.size()>0)&&(e2.size()>0))
    {
        pusht(*(e1.end()-1),*(e2.end()-1),3,2);
        e1.erase(e1.end()-1);
        e2.erase(e2.end()-1);
    }
    while (e1.size()>2)
    {
        pusht(*(e1.end()-1),*(e1.end()-2),3,2);
        pusht(*(e1.end()-2),*(e1.end()-3),2,3);
        e1.erase(e1.end()-1);
        e1.erase(e1.end()-1);
        e1.erase(e1.end()-1);
    }
    while (e1.size()>0)
    {
        pushk(*(e1.end()-1),3);
        e1.erase(e1.end()-1);
    }
    while (e2.size()>1)
    {
        pusht(*(e2.end()-1),*(e2.end()-2),2,2);
        e2.erase(e2.end()-1);
        e2.erase(e2.end()-1);
    }
    if (e2.size()==1) pushk(*(e2.end()-1),2);

    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i].size()/2<<endl;
        for (int j=ans[i].size()/2;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
        cout<<endl;
        for (int j=0;j<ans[i].size()/2;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}