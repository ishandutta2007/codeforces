#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 200200
#define MAXP 3000300
#define MAXK 20
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int p[MAXP]; int p2;
int counter;
int N;
ll w[MAXK]; ll invw[MAXK]; ll inverse[MAXK];
ll nextPowerofTwo[(1<<MAXK)];
vector<vector<ll> > q;
vector<ll> emptyVector;
vector<ll> finalProd;
bool comp(vector<ll> a, vector<ll> b)
{
    return a.size() < b.size();
}
ll power(ll a, ll b)
{
    ll cur1 = (b%2 ? a: 1); ll cur2 = a;
    for(int i=1; i<30; i++)
    {
        cur2 = cur2*cur2%MOD;
        if((1<<i) & b)
        {
            cur1 = cur1 * cur2 % MOD;
        }
    }
    return cur1;
}
ll inv(ll a)
{
    return power(a, MOD-2);
}
vector<ll> fft(vector<ll> a, int n, bool flag)
{
    vector<ll> b;
    vector<ll> temp;
    b.resize((1<<n), 0);
    temp.resize((1<<n), 0);
    for(int i=0; i<a.size(); i++)
    {
        b[i] = a[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<(1<<(n-i)); j++)
        {
            ll w2 = 1;
            for(int k=0; k<(1<<i); k++)
            {
                temp[j+(k<<(n-i))] = b[(j+(k<<(n-i+1)))%(1<<n)] + w2*b[(j+(k<<(n-i+1))+(1<<(n-i)))%(1<<n)];
                if(flag) w2 = w2*w[i]%MOD;
                else w2 = w2*invw[i]%MOD;
            }
        }
        for(int j=0; j<(1<<n); j++)
        {
            b[j] = temp[j]%MOD;
        }
    }
    return b;
}
vector<ll> multiply(vector<ll> a, vector<ll> b)
{
    int degree = nextPowerofTwo[a.size()+b.size()-1];
    vector<ll> c1 = fft(a, degree, true);
    vector<ll> c2 = fft(b, degree, true);
    vector<ll> c;
    vector<ll> d;
    c.resize(c1.size());
    for(int i=0; i<c1.size(); i++)
    {
        c[i] = c1[i]*c2[i]%MOD;
    }
    d = fft(c, degree, false);
    for(int i=0; i<d.size(); i++)
    {
        d[i] = d[i]*inverse[degree]%MOD;
    }
    d.erase(d.begin()+a.size()+b.size()-1, d.end());
    return d;
}
vector<ll> solve(vector<vector<ll> > a)
{
    if(a.size() == 1) return a[0];
    vector<vector<ll> > b, c;
    int counter1 = 0;
    int counter2 = 0;
    for(int i=0; i<a.size(); i++)
    {
        counter1 += (a[i].size()-1);
    }
    for(int i=0; i<a.size(); i++)
    {
        counter2 += (a[i].size()-1);
        if(counter2 > counter1/2 && i > 0)
        {
            c.push_back(a[i]);
        }
        else
        {
            b.push_back(a[i]);
        }
    }
    return multiply(solve(b), solve(c));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>p2;
        p[p2]++;
    }
    for(int i=0; i<MAXK; i++)
    {
        w[i] = power(3, (MOD-1)/(1<<i));
        invw[i] = inv(w[i]);
        inverse[i] = inv((1<<i));
    }
    for(int i=1; i<(1<<MAXK); i++)
    {
        nextPowerofTwo[i] = nextPowerofTwo[i-1];
        if((1<<nextPowerofTwo[i]) < i) nextPowerofTwo[i] += 1;
    }
    for(int i=2; i<MAXP; i++)
    {
        if(p[i])
        {
            q.push_back(emptyVector);
            q[counter].resize(p[i]+1, 1);
            ++counter;
        }
    }
    sort(q.begin(), q.end(), comp);
    finalProd = solve(q);
    cout<<finalProd[N/2]<<endl;
}