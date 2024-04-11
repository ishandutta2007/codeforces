#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vvint vector<vint>
#define vint vector<int>
#define pdd pair<double,double>
typedef long long LL;
#pragma comment(linker, "/STACK:167177216")
LL n,k,h;
struct p
{
    int first,second,pos;
};
vector<p> v;
bool f(double t)
{
    int u = 1;
    for(int i = 0;i < n;++i)
    {
        if(v[i].second * t + 1e-10 >= u * h)
            u++;
    }
    return u > k;
}
bool cmp(p a,p b)
{   
    if(a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    cin >> n >> k >> h;
    v.resize(n);
    for(int i = 0;i < n;++i)
    {
        scanf("%d",&v[i].first);
        v[i].pos = i;
    }
    for(int i = 0;i < n;++i)
        scanf("%d",&v[i].second);
    sort(v.begin(),v.end(),cmp);
    double l = 0, r = 1e9,M;
    for(int i = 0;i < 100;++i)
    {
        double m = (r + l) / 2;
        if(f(m))
        {
            r = m;
            M = m;
        }
        else
            l = m;
    }
    double m = M;
    int u = 1;
    for(int i = 0;i < n;++i)
        if(v[i].second * m + 1e-10 >= u * h)
        {
            printf("%d ",v[i].pos + 1);
            u++;
            if(u > k)
                return 0;
        }
    return 0;
}