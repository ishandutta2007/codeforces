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

int a,b,c,d,e,f,x,len,x0,x1,x2,u0,u1,u2,c0,c1,c2;
int main()
{
    scanf("%d %d %d %d %d %d",&a,&d,&f,&b,&e,&c);
    if ((a+b-d)%2!=0)
    {
        printf("-1\n");
        return 0;
    }
    x=(a+b-d)/2;
    len=x+d;
    for (int k=0;k<=100000;k++)
    {
        x0=x,x1=a-x,x2=d-x1;
        u0=k-f+x0+x1+x2;
        u1=e-k-x2;
        u2=c-k-x0;
        if ((u1+u2)%2!=0) continue;
        c1=(u1+u2)/2;
        if ((u0-u2)%2!=0) continue;
        c0=(u0-u2)/2;
        c2=u0-c0-c1;
        if ((c0>=0)&&(c1>=0)&&(c2>=0)&&(c0<=x0)&&(c1<=x1)&&(c2<=x2))
        {
            len+=k;
            printf("%d\n",len);
            for (int i=1;i<=len;i++) printf("a");printf("\n");
            for (int i=1;i<=x0+x1;i++) printf("b");
            for (int i=1;i<=x2;i++) printf("a");
            for (int i=1;i<=k;i++) printf("a");printf("\n");
            for (int i=1;i<=x0;i++) printf("a");
            for (int i=1;i<=x1+x2;i++) printf("b");
            for (int i=1;i<=k;i++) printf("a");printf("\n");
            for (int i=1;i<=c0;i++) printf("a");
            for (int i=1;i<=x0-c0;i++) printf("b");
            for (int i=1;i<=c1;i++) printf("a");
            for (int i=1;i<=x1-c1;i++) printf("b");
            for (int i=1;i<=c2;i++) printf("a");
            for (int i=1;i<=x2-c2;i++) printf("b");
            for (int i=1;i<=k;i++) printf("b");printf("\n");
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}