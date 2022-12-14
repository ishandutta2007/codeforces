#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[1000000];
int n;
long long k;
bool check(long long mid)
{
    long long num;
    for (int i=0;i+1<n;i++)
    {
        num = mid*k;
        num-=b[i];
        if (num<0)return 0;
        b[i+1]=max(a[i]-num,0LL);
    }
    num = mid*k;
    if (b[n-1]+a[n-1]<=num)
        return 1;
    return 0;
}
int main()
{
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];


        long long ans = 0;
    long long have = a[0];
    for(int i=1; i<n; i++) {
        long long rem = 0;
        long long how = 0;
        ans += have / k;
        how = have / k;
        if (have % k) ans++, how++;
        rem = how * k - have;
        have = 0;
        if (rem > a[i]) have = 0;
        else have = a[i] - rem;
    }

    if (have) {
            ans+= have / k + (have % k != 0);
    }
    cout << ans << endl;
    return 0;

}