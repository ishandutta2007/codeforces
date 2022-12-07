#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define MAXN 200200
#define LOGN 18
using namespace std;
typedef long long ll;
int T;
int N;
ll b[MAXN];
ll last_a, cur_a;
ll gcd_sparse_table[LOGN][MAXN];
void solve()
{
    cin>>N;
    cin>>last_a;
    int best = 0;
    for(int i=1; i<N; i++)
    {
        cin>>cur_a;
        b[i] = cur_a-last_a;
        gcd_sparse_table[0][i] = abs(b[i]);
        last_a = cur_a;
    }
    for(int j=1; j<LOGN; j++)
    {
        for(int i=1; i<N; i++)
        {
            if((i+(1<<j)) <= N)
            {
                gcd_sparse_table[j][i] = __gcd(gcd_sparse_table[j-1][i], gcd_sparse_table[j-1][i+(1<<(j-1))]);
            }
            else
            {
                gcd_sparse_table[j][i] = 1;
            }
        }
    }
    for(int i=1; i<N; i++)
    {
        ll cur_gcd = 0;
        int cur_length = 0;
        int cur_idx = i;
        for(int j=LOGN-1; j>=0; j--)
        {
            if(__gcd(cur_gcd, gcd_sparse_table[j][cur_idx]) != 1)
            {
                cur_gcd = __gcd(cur_gcd, gcd_sparse_table[j][cur_idx]);
                cur_length += (1<<j);
                cur_idx += (1<<j);
            }
            if(cur_idx == N) break;
        }
        best = max(best, cur_length);
    }
    cout<<best+1<<endl;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}