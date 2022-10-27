#include <iostream>
#include <algorithm>
using namespace std;
int a[100], n, m;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++) cin >> a[i];
    sort(a+1, a+1+m);int res = 1000000;
    for(int i=1;i<=m-n+1;i++)res=min(res,a[i+n-1]-a[i]);
    cout<<res<<endl;
}