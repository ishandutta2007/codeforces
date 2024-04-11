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
int main()
{
    int n;
    cin >> n;
    if(n & 1)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1;i <= n / 2;++i)
        cout << i * 2 << ' ' << i * 2 - 1 << ' ';
    return 0;
}