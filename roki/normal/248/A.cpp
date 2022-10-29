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
    int n,q[2][2];
int main()
{
    cin >> n;
    for(int i = 0;i < n;++i)
    {
        bool a,b;
        cin >> a >> b;
        q[0][!a]++;
        q[1][!b]++;
    }
    cout << (min(q[0][0],q[0][1]) + min(q[1][0],q[1][1])) << endl;
    return 0;
}