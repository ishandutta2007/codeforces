#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll M = 998244353;
const int D = (1<<19);
const int LOGD = 19;
const int LOGM = 30;
int N, x, y, Q, l; bool flag;
ll pow(ll a, ll b)
{
    ll cur = a; ll cur1 = (b & 1 ? a : 1);
    for(int i=1; i<LOGM; i++)
    {
        cur = cur*cur%M;
        if(b & (1<<i))
        {
            cur1 = cur1*cur%M;
        }
    }
    return cur1;
}
ll w[LOGD+1];
ll cur[D];
ll temp[D];
vector<ll> fft(vector<ll> p)
{
    for(int i=0; i<D; i++)
    {
        if(i < p.size())
        {
            cur[i] = p[i];
        }
        else
        {
            cur[i] = 0;
        }
    }
    for(int i=1; i<=LOGD; i++)
    {
        for(int j=0; j<D; j++)
        {
            temp[j] = cur[j];
        }
        for(int j=0; j<(D >> i); j++)
        {
            ll w0 = 1;
            for(int k=0; k<(1<<i); k++)
            {
                cur[j+k*(D >> i)] = (temp[j+((2*k) & ((1<<i)-1))*(D >> i)] + w0*temp[j+((2*k) & ((1<<i)-1))*(D >> i) + (D >> i)]) % M;
                w0 = w0 * w[i] % M;
            }
        }
    }
    vector<ll> p_fft;
    for(int i=0; i<D; i++)
    {
        p_fft.push_back(cur[i]);
    }
    return p_fft;
}
vector<ll> poly_multiply(vector<ll> a1, vector<ll> a2)
{
    vector<ll> b1 = fft(a1);
    vector<ll> b2 = fft(a2);
    vector<ll> b3;
    ll inv = pow(D, M-2);
    for(int i=0; i<b1.size(); i++)
    {
        b3.push_back(b1[i]*b2[i]%M*inv%M);
    }
    w[LOGD] = pow(3, M-1-(M-1)/D);
    for(int i=LOGD-1; i>=0; i--)
    {
        w[i] = w[i+1]*w[i+1]%M;
    }
    vector<ll> a3 = fft(b3);
    return a3;
}
vector<ll> p1, p2, p3; int ai;
bool g[D];
vector<int> d[D];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w[LOGD] = pow(3, (M-1)/D);
    for(int i=LOGD-1; i>=0; i--)
    {
        w[i] = w[i+1]*w[i+1]%M;
    }
    for(int i=1; i<D; i++)
    {
        for(int j=i; j<D; j += i)
        {
            d[j].push_back(i);
        }
    }
    for(int i=1; i<D; i++)
    {
        reverse(d[i].begin(), d[i].end());
    }
    cin>>N>>x>>y;
    for(int i=0; i<=N; i++)
    {
        cin>>ai;
        while(p1.size() < ai)
        {
            p1.push_back(0);
        }
        p1.push_back(1);
    }
    p2 = p1;
    reverse(p2.begin(), p2.end());
    p3 = poly_multiply(p1, p2);
    for(int i=x+1; i<p3.size(); i++)
    {
        if(p3[i] > 0)
        {
            g[i-x] = true;
        }
    }
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>l;
        flag = false;
        for(int j=0; j<d[l/2].size(); j++)
        {
            if(d[l/2][j] > y && g[d[l/2][j]-y])
            {
                cout<<d[l/2][j]*2<<" ";
                flag = true;
                break;
            }
        }
        if(!flag) cout<<-1<<" ";
    }
}