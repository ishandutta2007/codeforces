#include <bits/stdc++.h>
#define MAXN 200100
using namespace std;
typedef long long ll;
int T, N;
ll a[MAXN];
bool flag; ll best;
void solve()
{
    cin>>N;
    ll sum_pos = 0; ll num_pos = 0;
    ll sum_neg = 0; ll num_neg = N;
    ll best = -LLONG_MAX;
    ll t, c; //line of answer in terms of t
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        sum_neg += a[i];
    }
    sort(a, a+N);
    while(num_pos <= N)
    {
        if(1 <= num_neg && num_neg < N)
        {
            t = (a[N-1]*num_neg + sum_neg) + (a[0]*num_pos + sum_pos) - (a[N-1] + a[0]);
            c = sum_neg * a[N-1] + sum_pos * a[0] - a[N-1] * a[0];
            ll cur = max(-a[num_neg-1]*t + c, -a[num_neg]*t + c);
            best = max(best, cur);
        }
        else if(num_neg == 0)
        {
            t = (sum_pos - a[0] + (N-1)*a[0]);
            c = a[0]*(sum_pos-a[0]);
            if(t > 0)
            {
                cout<<"INF"<<endl;
                return;
            }
            else
            {
                best = max(best, -a[0]*t+c);
            }
        }
        else if(num_pos == 0)
        {
            t = (sum_neg - a[N-1] + (N-1)*a[N-1]);
            c = a[N-1]*(sum_neg-a[N-1]);
            if(t < 0)
            {
                cout<<"INF"<<endl;
                return;
            }
            else
            {
                best = max(best, -a[N-1]*t+c);
            }
        }
        sum_neg -= a[num_neg-1];
        sum_pos += a[num_neg-1];
        --num_neg;
        ++num_pos;
    }
    cout<<best<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}