#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 1020
#define MOD 1000000007
using namespace std;
typedef long long ll;
int Q;
int x, y;
vector<int> primes;
vector<int> cur;
bool flag;
ll binom[MAXN*MAXN][20];
ll power[MAXN*MAXN];
ll ans;
int main()
{
    cin>>Q;
    for(int i=2; i<MAXN; i++)
    {
        flag = false;
        for(int j=2; (j*j)<=i; j++)
        {
            if(i%j==0)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            primes.push_back(i);
        }
    }
    binom[0][0] = 1;
    power[0] = 1;
    for(int i=1; i<MAXN*MAXN; i++)
    {
        binom[i][0] = 1;
        power[i] = 2*power[i-1];
        power[i] %= MOD;
        for(int j=1; j<=19; j++)
        {
            binom[i][j] = binom[i-1][j-1]+binom[i-1][j];
            binom[i][j] %= MOD;
        }
    }
    for(int i=0; i<Q; i++)
    {
        cin>>x>>y;
        ans = 1;
        cur.clear();
        for(int j=0; j<primes.size(); j++)
        {
            if(x%primes[j]==0)
            {
                cur.push_back(0);
                while(x%primes[j]==0)
                {
                    x = x/primes[j];
                    cur[cur.size()-1]++;
                }
            }
        }
        if(x>1)
        {
            cur.push_back(1);
        }
        for(int j=0; j<cur.size(); j++)
        {
            ans *= binom[cur[j]+y-1][cur[j]];
            ans %= MOD;
        }
        ans *= power[y-1];
        ans %= MOD;
        cout<<ans<<'\n';
    }
}