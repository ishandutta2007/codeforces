#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PIC pair<int, char>
#define VI vector<int>
#define VLL vector<ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

int q, Count = 1;

ui x;

char a;

int p[32*200007];
int c[32*200007][2];
int w[32*200007];

map<ui, int> pos;

void add(ui v)
{
    int index = 1;

    ++w[index];

    for(int b = 31; b >= 0; --b)
    {
        if(v & (1<<b))
        {
            if(c[index][1])
            {
                index = c[index][1];
            }
            else
            {
                p[++Count] = index;
                c[index][1] = Count;
                index = Count;
            }
        }
        else
        {
            if(c[index][0])
            {
                index = c[index][0];
            }
            else
            {
                p[++Count] = index;
                c[index][0] = Count;
                index = Count;
            }
        }

        ++w[index];
    }

    pos[v] = index;
}

void del(ui v)
{
    int index = pos[v];

    --w[index];

    for(int b = 0; b <= 31; ++b)
    {
        index = p[index];

        --w[index];
    }
}

ui query(ui v)
{
    int index = 1;

    ui res = 0;

    for(int b = 31; b >= 0; --b)
    {
        if(v & (1<<b))
        {
            if(c[index][0] && w[c[index][0]])
            {
                index = c[index][0];
                res += (1<<b);
            }
            else
            {
                index = c[index][1];
            }
        }
        else
        {
            if(c[index][1] && w[c[index][1]])
            {
                index = c[index][1];
                res += (1<<b);
            }
            else
            {
                index = c[index][0];
            }
        }
    }

    return res;
}

int main()
{
    scanf("%d", &q);

    add(0);

    while(q--)
    {
        scanf(" %c%d", &a, &x);

        if(a=='+')
        {
            add(x);
        }

        if(a=='-')
        {
            del(x);
        }

        if(a=='?')
        {
            printf("%u\n", query(x));
        }
    }
}