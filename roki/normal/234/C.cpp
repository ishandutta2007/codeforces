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
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   
    int a[100000],n,n1 = 0,fm = 1e9,lm = 1e9,fp = 1e9,lp = 1e9,t1 = 0,t2 = 0;
    cin >> n;
    for(int i = 0;i < n;++i)
    {
        int t;
        cin >> t;
        if(t == 0)
            n1++;
        if(t < 0)
            t1++;
        if(t > 0)
            t2++;
        a[i] = t;
    }
    int q = 0,w = 0,ans = 1e9;
    for(int i = 0;i < n - 1;++i)
    {
        if(a[i] < 0)
            q++;
        if(a[i] > 0)
            w++;
        ans = min(ans,w + t1 - q);
    }
    cout << n1 + ans << endl;
    return 0;
}