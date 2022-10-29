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
    bool t = 0;
    int a,b,c,k;
    cin >> a >> b >> c;
    k = b - a % b;
    for(;k <= c - a;k += b)
    {
        cout << k << ' ';
        t = 1;
    }
    if(!t)
        cout << -1;
    return 0;
}