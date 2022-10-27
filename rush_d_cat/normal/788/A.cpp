#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
int n;
LL a[100000+10];
vector<LL> v;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    LL minc = 0, sum = 0, ans = 0;
    for(int i=2;i<=n;i++)
    {
        LL tmp = abs(a[i]-a[i-1])*(i%2?(-1):1);
        sum += tmp;
        if(i%2) minc = min(minc, sum);
        ans = max(sum-minc, ans);
    }
    minc = 0, sum = 0;
    for(int i=3;i<=n;i++)
    {
        LL tmp = abs(a[i]-a[i-1])*(i%2?1:(-1));
        sum += tmp;
        if(i%2==0) minc = min(minc, sum);
        ans = max(sum-minc, ans);
    }
    cout << ans << endl;
}