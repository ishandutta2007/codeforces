# include<iostream>
# include<iomanip>
#include <cstdio>
# include <algorithm>
using namespace std;
struct hit
{
    long long nom;
    long long denom;
};
hit a[3000001];
hit first[3000000];
hit second[3000000];
    int n,x,y;
bool comp(hit a,hit b)
{
    return a.nom*b.denom<b.nom*a.denom;
}
bool same(hit a,hit b)
{
    return a.nom*b.denom==a.denom*b.nom;
}
int tot=0;
void calc()
{
    int i=1,j=1;
    while(i<=x && j<=y)
    {
        if (comp(first[i],second[j]))
            a[tot++]=first[i],i++;
        else
            a[tot++]=second[j],j++;
    }
    while(i<=x)
        a[tot++]=first[i++];
    while(j<=y)
        a[tot++]=second[i++];
}
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    for (int i=1;i<=x;i++)
    {
        first[i].nom=i;
        first[i].denom=x;
    }
    for (int i=1;i<=y;i++)
    {
        second[i].nom=i;
        second[i].denom=y;
    }
    calc();
        int need;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&need);
        need--;
        need=(need%tot);
        if ((need>0 && same(a[need],a[need-1])) || (need<tot-1 && same(a[need],a[need+1])))
            printf("Both\n");
        else if (a[need].denom==x)
            printf("Vanya\n");
        else
            printf("Vova\n");

    }
}