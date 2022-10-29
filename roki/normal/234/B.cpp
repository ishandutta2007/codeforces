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
    
    int n,k;
    cin >> n >> k;
    vector<pii> a(n);
    for(int i = 0;i < n;++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(),a.rend());
    cout << a[k - 1].first << endl;
    for(int i = 0;i < k;++i)
        cout << a[i].second + 1 << ' ';
    return 0;
}