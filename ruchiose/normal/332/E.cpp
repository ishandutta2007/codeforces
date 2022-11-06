// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MOD = 2333333;

#define ee(i) for (int i = 0; i < 3; i++)

struct Hash
{
    int res[3];
    void clear()
    {
        ee(i) res[i] = 0;
    }
    void att(char ch)
    {
        ee(i) res[i] = ((res[i] * 127) + int(ch)) % (MOD + i);
    }
};

bool operator == (Hash a, Hash b)
{
    ee(i) if (a.res[i] != b.res[i]) return false;
    return true;
}

char p[1000010], s[210];
int P, S, K;

Hash atLoc[2010];

string Key;

string min(const string &a, const string &b)
{
    int minLen = min(a.size(), b.size());
    int i;
    fortodo(i, 0, minLen - 1)
        {
            if (a[i] < b[i]) return a;
            if (a[i] > b[i]) return b;
        }
    if (a.size() < b.size())
        return a;
    else
        return b;
}

Hash cluster[210];

int dp[210];

int main()
{
    gets(p); P = strlen(p);
    gets(s); S = strlen(s);
    scanf("%d", &K);
    int i;
    fortodo(i, 0, K - 1) atLoc[i].clear();
    fortodo(i, 0, P - 1) atLoc[i % K].att(p[i]);
    int maxcnt = min(S, K);
    Key = "2";
    int cnt;
    fortodo(cnt, 1, maxcnt)
        {
            fortodo(i, 0, cnt - 1) cluster[i].clear();
            fortodo(i, 0, S - 1) cluster[i % cnt].att(s[i]);
            dp[cnt] = K;
            for (i = cnt - 1; i >= 0; i--)
                {
                    dp[i] = dp[i + 1] - 1;
                    while ((dp[i] >= 0) && !(cluster[i] == atLoc[dp[i]])) dp[i]--;
                }
            if (dp[0] < 0) continue;
            int a = 0;
            string s = "";
            fortodo(i, 0, K - 1)
                if (dp[a] == i)
                    {
                        s += '1';
                        a++;
                    }
                else
                    s += '0';
            Key = min(Key, s);
        }
    if (Key == "2")
        puts("0");
    else
        cout << Key << endl;
}