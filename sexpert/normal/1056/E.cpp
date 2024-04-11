#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 3;
const ll MOD = 1e9 + 7;
vector<ll> bases = {37};
vector<vector<ll>> rhash;
string s, t;

ll modpow(ll a, ll b)
{
    if(b < 0)
        b += (MOD - 1);
    if(b == 0)
        return 1;
    if(b % 2)
        return (a * modpow(a, b - 1))%MOD;
    ll p = modpow(a, b/2);
    return (p * p) % MOD;
}

void buildhash()
{
    int n = t.length();
    vector<ll> mul(2, 1), cur(2);
    rhash.push_back({0, 0});
    for(int i = 0; i < n; i++)
    {
        rhash.push_back({});
        for(int j = 0; j < bases.size(); j++)
        {
            ll p = bases[j];
            cur[j] = (cur[j] + mul[j]*(ll)(t[i] - 'a' + 1)) % MOD;
            mul[j] = (mul[j] * p) % MOD;
            rhash[i + 1].push_back(cur[j]);
        }
    }
}

bool eq(vector<ll> h1, vector<ll> h2)
{
    return (h1[0] == h2[0]);
}

vector<ll> gethash(int l, int r)
{
    l++;
    r++;
    vector<ll> ans;
    for(int i = 0; i < bases.size(); i++)
    {
        ll p = bases[i];
        ll x = (rhash[r][i] - rhash[l - 1][i] + MOD) % MOD;
        x = (x * modpow(p, 1 - l)) % MOD;
        ans.push_back(x);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s >> t;
    buildhash();
    int cz = 0, co = 0;
    for(char c : s)
    {
        if(c == '0')
            cz++;
        else
            co++;
    }
    if(co > cz)
    {
        swap(co, cz);
        for(int i = 0; i < s.length(); i++)
            s[i] = (s[i] == '0') ? '1' : '0';
    }
    int n = t.length(), ans = 0;
    for(int zlen = 1; zlen*cz + co <= n; zlen++)
    {
        if((n - zlen*cz)%co)
            continue;
        int olen = (n - zlen*cz)/co;
        bool seenz = false, seeno = false, good = true;
        vector<ll> hz, ho;
        for(int i = 0, j = 0; i < s.length(); i++)
        {
            char c = s[i];
            if(c == '0')
            {
                if(!seenz)
                {
                    hz = gethash(j, j + zlen - 1);
                    seenz = true;
                }
                else
                {
                    if(!eq(hz, gethash(j, j + zlen - 1)))
                    {
                        good = false;
                        break;
                    }
                }
                j += zlen;
            }
            else
            {
                if(!seeno)
                {
                    ho = gethash(j, j + olen - 1);
                    seeno = true;
                }
                else
                {
                    if(!eq(ho, gethash(j, j + olen - 1)))
                    {
                        good = false;
                        break;
                    }
                }
                j += olen;
            }
        }
        if(!good || eq(ho, hz))
            continue;
        ans++;
    }
    cout << ans << endl;
}