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

const int maxn=100005;

set<int> diss[maxn];
map<int,int> lsh;
map<int,int>::iterator lsg;
vector<int> bak;
set<int> ans;
vector<PII> store[maxn];
int pt[maxn],hy[maxn],times[maxn];
set<int> nows[maxn];
vector<int> pri;
int m,n,c1,flag,nt;

int main()
{
    scanf("%d %d",&m,&n);
    int data[m+1][n+1];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&data[i][j]);
    for (int i=1;i<=m;i++)
    {
        bak.clear();
        for (int j=1;j<=n;j++)
            if (data[i][j]==-1) diss[i].insert(j); else bak.p_b(data[i][j]);
        sort(bak.begin(),bak.end());
        if (bak.size()==0) continue;
        c1=1;
        lsh.clear();
        lsh.insert(m_p(bak[0],1));
        for (int j=1;j<bak.size();j++)
        {
            if (bak[j]!=bak[j-1]) ++c1;
            lsh.insert(m_p(bak[j],c1));
        }
        for (int j=1;j<=n;j++)
            if (data[i][j]!=-1)
            {
                lsg=lsh.find(data[i][j]);
                data[i][j]=lsg->second;
            }
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            if (data[i][j]!=-1) store[i].p_b(m_p(data[i][j],j));
        sort(store[i].begin(),store[i].end());
        pt[i]=0;
    }
    memset(times,0,sizeof(times));
    ans.clear();
    for (int i=1;i<=m;i++) hy[i]=1;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            if (data[i][j]==-1)
            {
                ++times[j];
                if (times[j]==m) ans.insert(j);
            }
        while (pt[i]<store[i].size())
        {
            if (store[i][pt[i]].first==hy[i])
            {
                nows[i].insert(store[i][pt[i]].second);
                ++times[store[i][pt[i]].second];
                if (times[store[i][pt[i]].second]==m) ans.insert(store[i][pt[i]].second);
            }
            else
                break;
            ++pt[i];
        }
    }
    flag=1;
    pri.clear();
    for (int i=1;i<=n;i++)
    {
        if (ans.size()==0)
        {
            flag=0;
            break;
        }
        nt=*ans.begin();
        pri.p_b(nt);
        times[nt]=0;
        ans.erase(nt);
        for (int j=1;j<=m;j++)
        {
            if (data[j][nt]!=-1)
            {
                nows[j].erase(nt);
                if (nows[j].size()==0)
                {
                    ++hy[j];
                    while (pt[j]<store[j].size())
                    {
                        if (store[j][pt[j]].first==hy[j])
                        {
                            nows[j].insert(store[j][pt[j]].second);
                            ++times[store[j][pt[j]].second];
                            if (times[store[j][pt[j]].second]==m) ans.insert(store[j][pt[j]].second);
                        }
                        else
                            break;
                        ++pt[j];
                    }
                }
            }
        }
    }
    if (flag==0) printf("-1\n"); else
    {
        printf("%d",pri[0]);
        for (int i=1;i<n;i++) printf(" %d",pri[i]);
        printf("\n");
    }

    return 0;
}