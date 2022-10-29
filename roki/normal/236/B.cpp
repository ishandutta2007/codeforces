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
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vvint vector<vint>
#define vint vector<int>
#define pdd pair<double,double>
typedef long long LL;
#pragma comment(linker, "/STACK:167177216")
int d(int i)
{
    int res = 1;
    if(i == 1)
        return 1;
    vint v;
    if(i % 2 == 0)
    {
        v.pb(0);
        while(i % 2 == 0)
        {
            i /= 2;
            v[0]++;
        }
    }
    for(int j = 3;j * j <= i;++j)
    {
        if(i % j == 0)
        {
            v.pb(0);
            while(i % j == 0)
            {
                i /= j;
                v[v.size() - 1]++;
            }
        }
    }
    if(i > 1)
        v.pb(1);
    for(i = 0;i < v.size();++i)
        res *= v[i] + 1;
    return res;
}
int main()
{
    int a,b,c;
    LL res = 0;
    cin >> a >> b >> c;
    for(int i = 1;i <= a;++i)
        for(int j = 1;j <= b;++j)
            for(int k = 1;k <= c;++k)
            {
                res += d(i * j * k);
                res &= ((1 << 30) - 1);
            }
    cout << res;
    return 0;   
}