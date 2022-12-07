#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 48
using namespace std;
int N, K, M;
int a[MAXN];
int sum;
int cur, best, ans, cur1;
int main()
{
    cin>>N>>K>>M;
    for(int i=0; i<K; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sort(a, a+K);
    for(int i=0; i<=N; i++)
    {
        cur = sum * i;
        if(cur > M)
        {
            break;
        }
        ans = (K+1)*i;
        for(int j=0; j<K; j++)
        {
            cur1 = min((M-cur)/a[j], N-i);
            ans += cur1;
            cur += (cur1 * a[j]);
        }
        best = max(best, ans);
    }
    cout<<best<<endl;
}