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
    int sum = 0,a[1 << 17];
    int n;
    cin >> n;
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int p = 0,res = 0;
    for(int i = 0;i < n - 1;++i)
    {
        p += a[i];
        if(p == sum - p)
            res++;
    }
    cout << res << endl;
    return 0;   
}