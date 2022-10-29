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
    int a[3];
    for(int i = 0;i < 3;++i)
        cin >> a[i];
    int t = 0;
    while(a[0] > 0 || a[1] > 0 || a[2] > 0)
        a[(t++) % 3] -= 2;
    cout << t + 29 << endl;
    return 0;   
}