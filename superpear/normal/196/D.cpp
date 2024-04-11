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

const int maxn=400005;
const int base=987654323;

int D,n,place,flag;
char st[maxn];
int a[maxn];
LL poc[maxn],hash1[maxn],hash2[maxn];

bool check(int s,int D)
{
    if (s<D) return false;
    LL c1=hash1[s]*poc[s-D]-hash1[s-D]*poc[s];
    LL c2=hash2[s]-hash2[s-D];
    return c1==c2;
}

int main()
{
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
    scanf("%d",&D);
    scanf("%s",st);
    n=strlen(st);
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++) a[i]=st[i-1]-96;
    int tt=n;
    while (a[tt]==26) a[tt]=1,--tt;
    if (tt==0)
    {
        printf("Impossible\n");
        return 0;
    }
    ++a[tt];
    poc[0]=1;
    for (int i=1;i<=n;i++) poc[i]=poc[i-1]*base;
    hash1[0]=0;
    for (int i=1;i<=n;i++) hash1[i]=hash1[i-1]*base+a[i];
    hash2[0]=0;
    for (int i=1;i<=n;i++) hash2[i]=hash2[i-1]+a[i]*poc[i-1];
    place=n;
    for (int i=D;i<=n;i++)
        if ((check(i,D))||((i>D)&&(check(i,D+1))))
        {
            place=i;
            break;
        }
    while (place>0)
    {
        flag=1;
        if ((place>=D)&&(check(place,D))) flag=0;
        if ((place>D)&&(check(place,D+1))) flag=0;
        if (flag==1) break;
        while (a[place]==26) --place;
        ++a[place];
        if (place>0)
        {
            hash1[place]=hash1[place-1]*base+a[place];
            hash2[place]=hash2[place-1]+a[place]*poc[place-1];
        }
    }
    if (place==0)
    {
        printf("Impossible\n");
        return 0;
    }
    memset(hash1,0,sizeof(hash1));
    memset(hash2,0,sizeof(hash2));
    for (int i=1;i<=place;i++)
    {
        hash1[i]=hash1[i-1]*base+a[i];
        hash2[i]=hash2[i-1]+a[i]*poc[i-1];
    }
    for (int i=place+1;i<=n;i++)
        for (int j=1;j<=26;j++)
        {
            hash1[i]=hash1[i-1]*base+j;
            hash2[i]=hash2[i-1]+j*poc[i-1];
            if ((!check(i,D))&&(!check(i,D+1)))
            {
                a[i]=j;
                break;
            }
        }
    for (int i=1;i<=n;i++) printf("%c",a[i]+96);printf("\n");

    return 0;
}