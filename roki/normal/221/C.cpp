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
typedef long long LL;
#define vint vector<int>
using namespace std;
#pragma comment(linker, "/STACK:167177216")
int main()
{
    int n;
    cin >> n;
    vint v;
    int a[100011];
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        v.pb(a[i]);
    }
    int ans = 0;
    sort(v.begin(),v.end());
    for(int i = 0;i < n;++i)
        ans += (a[i] != v[i]);
    if(ans == 0 || ans == 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}