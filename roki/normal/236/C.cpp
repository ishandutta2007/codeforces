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
int main()
{
    LL n;
    cin >> n;
    if(n % 6 == 0)
    {
        cout << (n - 1) * (n - 2) * (n - 3);
        return 0;
    }
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    if(n == 2)
    {
        cout << 2;
        return 0;
    }
    if(n % 2 == 0)
        cout << n * (n - 1) * (n - 3);
    else
        cout << n * (n - 1) * (n - 2);
    return 0;   
}