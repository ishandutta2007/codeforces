#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 6
#define MAXC 20
#define MAXM 18
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll inv(ll x)
{
    ll cur1 = x; ll cur2 = x;
    for(int i=1; i<30; i++)
    {
        cur2 = cur2*cur2%MOD;
        if((1<<i) & (MOD-2))
        {
            cur1 = cur1*cur2%MOD;
        }
    }
    return cur1;
}
const ll pct = inv(100);
bool conn[MAXN][MAXN];
int m[6][6][6];
ll p[MAXN][MAXN];
ll ans;
ll freq[(1<<MAXC)], freq2[(1<<MAXC)];
ll DP[(1<<MAXC)];
int N;
ll curp;
int counter;
int t;
ll rev(ll num)
{
    ll tot = 0;
    for(int i=0; i<MAXC; i++)
    {
        if((1<<i) & num)
        {
            tot += (1<<(19-i));
        }
    }
    return tot;
}
int main()
{
    cin>>N;
    for(int i=0; i<6; i++)
    {
        for(int j=i+1; j<6; j++)
        {
            for(int k=j+1; k<6; k++)
            {
                m[i][j][k] = m[j][k][i] = m[i][k][j] = m[j][i][k] = m[k][i][j] = m[k][j][i] = counter;
                ++counter;
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>p[i][j];
            p[i][j] *= pct;
            p[i][j] %= MOD;
        }
    }
    for(int i=N; i<6; i++)
    {
        p[i][i] = 1;
    }
    for(int i=0; i<(1<<MAXM); i++)
    {
        curp = 1;
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<6; k++)
            {
                if((1<<(6*j+k)) & i)
                {
                    conn[j][k] = true;
                    curp *= p[j][k]; curp %= MOD;
                }
                else
                {
                    conn[j][k] = false;
                    curp *= (MOD+1-p[j][k]); curp %= MOD;
                }
            }
        }
        t = 0;
        for(int j=0; j<6; j++)
        {
            for(int k=0; k<6; k++)
            {
                for(int l=0; l<6; l++)
                {
                    if(k != j && l != k && l != j)
                    {
                        if(conn[0][j] && conn[1][k] && conn[2][l])
                        {
                            t = t | (1<<(m[j][k][l]));
                        }
                    }
                }
            }
        }
        freq[t] += curp; freq[t] %= MOD;
    }
    for(int i=0; i<(1<<MAXM); i++)
    {
        curp = 1;
        for(int j=3; j<6; j++)
        {
            for(int k=0; k<6; k++)
            {
                if((1<<(6*j-18+k)) & i)
                {
                    conn[j][k] = true;
                    curp *= p[j][k]; curp %= MOD;
                }
                else
                {
                    conn[j][k] = false;
                    curp *= (MOD+1-p[j][k]); curp %= MOD;
                }
            }
        }
        t = 0;
        for(int j=0; j<6; j++)
        {
            for(int k=0; k<6; k++)
            {
                for(int l=0; l<6; l++)
                {
                    if(k != j && l != k && l != j)
                    {
                        if(conn[3][j] && conn[4][k] && conn[5][l])
                        {
                            t = t | (1<<(m[j][k][l]));
                        }
                    }
                }
            }
        }
        freq2[t] += curp; freq2[t] %= MOD;
    }
    for(int i=0; i<(1<<MAXC); i++)
    {
        DP[i] = freq2[i];
    }
    for(int i=0; i<MAXC; i++)
    {
        for(int j=0; j<(1<<MAXC); j++)
        {
            if(j & (1<<i))
            {
                DP[j] += DP[j^(1<<i)];
                DP[j] %= MOD;
            }
        }
    }
    for(int i=0; i<(1<<MAXC); i++)
    {
        ans += (freq[i] * (MOD+1-DP[(1<<MAXC)-1-rev(i)]));
        ans %= MOD;
    }
    cout<<ans<<endl;
}