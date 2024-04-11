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
    vint v(4);
    for(int i = 0;i < 4;++i)
        cin >> v[i];
    sort(v.begin(),v.end());
    int res = 0,i = 0;
    v.pb(-1);
    while(i < 4)
    {
        if(v[i] == v[i + 1])
        while(v[i] == v[i + 1])
            res++,i++;
        else
            ++i;
    }
    cout << res;
    return 0;
}