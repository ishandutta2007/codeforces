#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100100
using namespace std;
typedef long long ll;
ll N, s;
ll l[MAXN];
ll prefix[MAXN];
int load[MAXN];
int cur, cur2, cur3, cur1;
bool test(ll x)
{
    ll total = N-1; ll total2 = s-1;
    l[1] = 1; cur = 1;
    while(total)
    {
        ++cur;
        l[cur] = x*l[cur-1];
        l[cur] = min(l[cur], total);
        total -= l[cur];
        total2 -= (l[cur] * cur);
    }
    return total2 >= 0;
}
bool judge(ll u, ll v, ll w)
{
    return (w*v+v*(v+1)/2) >= u;
}
void find_sequence(ll x)
{
    ll total = N-1;
    for(int i=1; i<=N; i++)
    {
        l[i] = 0;
    }
    l[1] = 1;
    s -= 1;
    for(int j=2; j<=N; j++)
    {
        while(total && l[j] < x*l[j-1])
        {
            if(judge(s-j, total-1, j))
            {
                ++l[j];
                s -= j;
                --total;
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{
    cin>>N>>s;
    if(s < 2*N-1 || s > (N*(N+1)/2))
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1; i<=N; i++)
    {
        if(test(i))
        {
            find_sequence(i);
            cout<<"Yes"<<endl;
            for(int j=1; j<=N; j++)
            {
                prefix[j] = prefix[j-1] + l[j];
            }
            cur = 1; l[1] = 0;
            for(int j=2; j<=N; j++)
            {
                if(!l[cur])
                {
                    ++cur;
                    cur1 = prefix[cur-2]+1;
                }
                if(load[cur1] == i)
                {
                    ++cur1;
                }
                l[cur]--;
                ++load[cur1];
                cout<<cur1<<" ";
            }
            return 0;
        }
    }
    cout<<"NO"<<endl;
}