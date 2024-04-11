#include <iostream>
#include <vector>
#define MAXN 100100
#define MOD (int) 1e9+7
using namespace std;
int N;
int a[MAXN];
vector<int> primes;
vector<int> factors[MAXN];
int compress[MAXN];
int used[MAXN];
int power[MAXN];
int cur, cur1, ans;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=2; i<MAXN; i++)
    {
        int cur = i; cur1 = 0;
        while(!primes.empty()&&(primes.size()>cur1&&primes[cur1]*primes[cur1]<=cur))
        {
            if(cur%primes[cur1]==0)
            {
                while(cur%primes[cur1]==0)
                {
                    cur = cur/primes[cur1];
                }
                factors[i].push_back(primes[cur1]);
            }
            cur1++;
        }
        if(factors[i].empty())
        {
            primes.push_back(i);
            factors[i].push_back(i);
        }
        if(cur > factors[i][factors[i].size()-1])
        {
            factors[i].push_back(cur);
        }
        compress[i] = 1;
        for(int j=0; j<factors[i].size(); j++)
        {
            compress[i] *= factors[i][j];
        }
    }
    compress[1] = 1;
    for(int i=0; i<N; i++)
    {
        a[i] = compress[a[i]];
    }
    power[0] = 1;
    for(int i=1; i<MAXN; i++)
    {
        power[i] = power[i-1]*2;
        power[i] %= MOD;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<(1<<(factors[a[i]].size())); j++)
        {
            cur = 1;
            cur1 = j;
            for(int k=factors[a[i]].size()-1; k>=0; k--)
            {
                if(power[k]<=cur1)
                {
                    cur1 -= power[k];
                    cur *= factors[a[i]][k];
                }
            }
            used[cur]++;
        }
    }
    ans = power[N]-1;
    for(int i=2; i<=MAXN; i++)
    {
        if(factors[i].size()%2==1)
        {
            ans += MOD;
            ans -= power[used[i]];
            ans += 1;
        }
        else
        {
            ans += power[used[i]];
            ans -= 1;
        }
        ans %= MOD;
    }
    cout<<ans<<endl;
}