#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false)
#define INF 1e18
#define MOD 1e9 + 7
#define MAXN 100000+10
#define MAXM 500000+10
int n,c,t[MAXN];
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>t[i];
    int cnt = 1;
    for(int i=2;i<=n;i++)
    {
        if(t[i]-t[i-1]>c) cnt=1;
        else cnt++;
    }
    cout<<cnt<<endl;
}