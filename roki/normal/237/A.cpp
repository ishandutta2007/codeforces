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
int a[100][100];
int main()
{
    int n,ans = 0;
    cin >> n;
    while(n--)
    {
        int q,w;
        cin >> q >> w;
        a[q][w]++;
        ans = max(ans,a[q][w]);
    }
    cout << ans;
    return 0;   
}