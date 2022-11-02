#include <iostream>
#include <algorithm>
#include <map>
#include <time.h>
 
using namespace std;
 
//Each of us know how it will end.
//I can change my P endlessly...
//No, I don't want to write 2 modules
//Meow  =<^.^>=
 
const long long SZ = 1e6 + 10;
const long long MOD = 1e9 + 7;
long long P = 0;
 
long long n;
string res = "";
long long has[SZ];
 
map<char, long long> mp;
 
void meow()
{
    while (P < 170)
        P = rand() % (long long)1e7;
}
 
long long get_pow(long long a, long long b)
{
    long long ans = 1;
    while (b > 1)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
        a %= MOD;
        ans %= MOD;
    }
    return a * ans % MOD;
}
 
long long get_has(long long L)
{
    long long ans_now = has[(long long)res.size() - 1];
    if (L != 0)
        ans_now -= has[L - 1] * get_pow(P, res.size() - L) % MOD;
    ans_now = (ans_now % MOD + MOD) % MOD;
    return ans_now;
}
 
void add_string()
{
    string s;
    cin >> s;
    long long h_now = 0;
    long long id = -1;
    for (long long i = 0; i < min(s.size(), res.size()); i++)
    {
        h_now = h_now * P + mp[s[i]];
        h_now %= MOD;
        if (h_now == get_has(res.size() - i - 1))
            id = i;
//        cout << i << " :     " << h_now << ' ' << get_has(res.size() - i - 1) << endl;
    }
    for (long long i = id + 1; i < s.size(); i++)
    {
        has[(long long)res.size()] = mp[s[i]];
        if (res.size() > 0)
            has[(long long)res.size()] += has[(long long)res.size() - 1] * P;
        has[(long long)res.size()] %= MOD;
        res += s[i];
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    time_t t;
    srand((unsigned)time(&t));
    meow();
    long long id = 1;
    for (char c = 'a'; c <= 'z'; c++, id++)
        mp[c] = id;
    for (char c = 'A'; c <= 'Z'; c++, id++)
        mp[c] = id;
    for (char c = '0'; c <= '9'; c++, id++)
        mp[c] = id;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        add_string();
//        cout << res << "\n";
    }
    cout << res;
    return 0;
}