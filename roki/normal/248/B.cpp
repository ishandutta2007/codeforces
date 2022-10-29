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
int main()
{
    int n;
    cin >> n;
    if(n < 3)
    {
        cout << -1;
        return 0;
    }
    if(n == 3)
    {
        cout << 210;
        return 0;
    }
    if(n % 6 == 4)
    {
        cout << 1;
        for(int i = 0;i < n - 3;++i)
            cout << 0;
        cout << 50;
        return 0;
    }
    if(n % 6 == 5)
    {
        cout << 1;
        for(int i = 0;i < n - 3;++i)
            cout << 0;
        cout << 80;
        return 0;
    }
    if(n % 6 == 0)
    {
        cout << 1;
        for(int i = 0;i < n - 4;++i)
            cout << 0;
        cout << 170;
        return 0;
    }
    if(n % 6 == 1)
    {
        cout << 1;
        for(int i = 0;i < n - 3;++i)
            cout << 0;
        cout << 20;
        return 0;
    }
    if(n % 6 == 2)
    {
        cout << 1;
        for(int i = 0;i < n - 4;++i)
            cout << 0;
        cout << 200;
        return 0;
    }
    if(n % 6 == 3)
    {
        cout << 1;
        for(int i = 0;i < n - 4;++i)
            cout << 0;
        cout << 110;
        return 0;
    }
    return 0;
}