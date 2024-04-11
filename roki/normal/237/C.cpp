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
bool prime[1000001];
int a,b,k;
bool f(int p)
{
    int l = a,num = 0;
    for(int i = 0;i < p;++i)
    {
        if(l % 2 != 0 || l == 2)
            num += !prime[l];
        l++;
    }
    l = a;
    for(int j = a;j <= b - p;++j)
    {
        if(num < k)
            return 0;
        if(l % 2 != 0 || l == 2)
            num -= !prime[l];
        if((l + p) % 2 != 0 || (l + p) == 2)
            num += !prime[l + p];
        l++;
    }
    if(num < k)
        return 0;
    return 1;
}
int main()
{
    prime[1] = 1;
    cin >> a >> b >> k;
    if(k == 0)
    {
        cout << 0;
        return 0;
    }
    for(int i = 3;i <= 1000000;++i)
        if(prime[i] == 0)
            for(int j = i + i;j <= 1000000;j += i)
                prime[j] = 1;
    int l = 1,r = b - a + 1;
    while(r - l > 1)
    {
        int m = (r + l) / 2;
        if(f(m))
            r = m;
        else
            l = m;
    }
    if(f(r))
    {
        while(f(r - 1))
            r--;
        cout << r;
    }
    else
        cout << -1;
    return 0;   
}