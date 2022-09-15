#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

struct LEM
{
    int m;
    int v;
    int id;
    bool operator<(const LEM& b) const { return m==b.m?v < b.v:m<b.m; }
};
LEM lemm[100010];
bool verify(int n,int k,int h,double T)
{
    int pickout = 0;
    for(int i = 0;i < n;i++)
    {
        if(((double)(h*(pickout+1))) <= (double)lemm[i].v*T)
        {
            pickout++;
            if(pickout >= k) break;
        }
    }
    return pickout >= k;
}

int main(void)
{
    int n = 0;
    int k = 0;
    int h = 0;
    scanf("%d %d %d",&n,&k,&h);
    for(int i = 0;i < n;i++) scanf("%d",&lemm[i].m);
    for(int i = 0;i < n;i++) scanf("%d",&lemm[i].v);
    for(int i = 0;i < n;i++) lemm[i].id = i+1;
    sort(lemm,lemm+n);
    double l = 0;
    double r = 10000000000;
    int fuck = 200;
    while(fuck--)
    {
        double mid = (l+r)/2.0;
        if(verify(n,k,h,mid)) r = mid;
        else l = mid;
    }
    int pickout = 0;
    for(int i = 0;i < n;i++)
    {
        if((double)((pickout+1)*h) <= (double)lemm[i].v*r)
        {
            printf("%d ",lemm[i].id);
            pickout++;
            if(pickout >= k) break;
        }
    }
    putchar('\n');
    while(getchar() != EOF);
    return 0;
}