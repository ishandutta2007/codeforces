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

const int maxn=5000;

int f[maxn+5],a[maxn+5],hash[maxn+5],b[maxn+5];
string st;
int n,flag,oc,k;

int main()
{
    f[1]=0,f[2]=0;
    for (int i=3;i<=maxn;i++)
    {
        memset(hash,0,sizeof(hash));
        for (int j=2;j<i;j++)
            hash[f[j-1]^f[i-j]]=1;
        for (int j=0;j<=maxn;j++)
            if (hash[j]==0)
            {
                f[i]=j;
                break;
            }
    }
    cin>>st;
    n=st.size();
    memset(a,0,sizeof(a));
    for (int i=2;i<n;i++)
        if (st[i-2]==st[i]) a[i]=1;
    flag=-1;
    for (int i=2;i<n;i++)
        if (a[i]==1)
        {
            for (int j=1;j<=n;j++) b[j]=a[j];
            b[i]=0,b[i-1]=0,b[i+1]=0;
            oc=0;
            k=0;
            for (int j=1;j<=n;j++)
                if (b[j]==1) ++k; else
                {
                    oc^=f[k+2];
                    k=0;
                }
            if (oc==0)
            {
                flag=i;
                break;
            }
        }
    if (flag==-1) cout<<"Second"<<endl; else cout<<"First"<<endl<<flag<<endl;

    return 0;
}