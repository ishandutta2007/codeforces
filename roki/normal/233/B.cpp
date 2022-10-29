#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pdd pair<double,double>
typedef long long LL;
#define vint vector<int>
#define vvint vector<vint>
#pragma comment(linker, "/STACK:167177216")
#include<set>
LL f(LL a)
{
    LL res = a % 10;
    while(a /= 10)
        res += a % 10;
    return res;
}
int main()
{
    LL n;
    cin >> n;
    LL t = sqrt(n + 0.0);
    for(LL i = t;i > t - 100 && i > 0;--i)
    {
        if(i * i + i * f(i) == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}