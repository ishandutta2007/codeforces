#include <iostream>
#include <fstream>
#include <iomanip>
#define MAXN 200200
using namespace std;
typedef long long ll;
ll a[MAXN];
ll prefix[MAXN];
int K, N;
ll ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    for(int i=K; i<=N; i++)
    {
        ans += (prefix[i]-prefix[i-K]);
    }
    cout<<fixed;
    cout<<setprecision(6);
    cout<<((double)(ans)/((double)(N-K+1)))<<endl;
}