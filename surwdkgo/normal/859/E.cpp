#include <stdio.h>
#include <vector>
int n;
int inp[100010][2];
int mp[200010];
int circ[200010];
int c0;
int vis[200010];

int v[400010];
int f[400010];
int a[400010];
int nv;
std::vector<int> e[400010];

const long long MOD = 1000000007;

long long pow(long long x, int a)
{
    if (a == 0) return 1;
    if (a == 1) return x % MOD;
    long long y = pow(x*x % MOD, a/2);
    return a%2 ? y *x % MOD : y;
}

long long inv(long long x)
{
    return pow(x%MOD, MOD-2);
}

long long dfs(int x, int allow)
{
    if (e[x].size() == 0)
    {
        return allow+1;
    }
    long long ans = 0;

    std::vector<long long> mem[2];
    for (int i=0; i<e[x].size(); i++)
    {
        //mem[0].push_back(dfs(e[x][i], 0));
        mem[1].push_back(dfs(e[x][i], 1));
        //printf("%d, %d\n", (int)mem[0][i], (int)mem[1][i]);
    }

    if (allow)
    {
        ans = ans + 1;
    }
    for (int i=0; i<e[x].size(); i++)
    {
        ans = (ans + mem[1][i])%MOD;
        if (i > 0)
        {
            ans = (ans + MOD-1 ) % MOD;
        }
    }
    return ans;
}

int main()
{
    long long ans = 1;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d%d", &inp[i][0], &inp[i][1]);
        mp[inp[i][0]] = inp[i][1];
    }
    c0 = 2*n+1;
    for (int i=1; i<=2*n; i++)
    {
        if (vis[i]) continue;
        if (mp[i] == 0) continue;

        int cur = i;
        bool mk = false;
        //printf ("-- %d", i);
        while (true)
        {
            //printf ("-1 %d\n", cur);
            vis[cur] = c0;
            int next = mp[cur];
            if (mp[next] == 0) break;

            if (vis[next])
            {
                if (vis[next] == c0)
                {
                    // circle
                    mk = true;
                    break;
                }
                else
                {
                    break;
                }
            }
            cur = next;
        }
        if (mk)
        {
            while (true)
            {
                circ[cur] = c0;
                int next = mp[cur];
                if (circ[next] == c0) break;
                cur = next;
            }
            if (mp[cur] == cur)
            {
                /*
                //printf ("- hcirc %d\n", c0);
                f[nv] = 1;
                v[nv++] = c0;
                a[c0] = 1;*/
            }
            else
            {
                //printf ("- circ %d\n", c0);
                //f[nv] = 1;
                //v[nv++] = c0;
                ans = ans * 2 % MOD;
            }
        }
        c0++;
    }
    for (int i=1; i<=2*n; i++)
    {
        if (circ[i] == 0 && mp[i] != 0)
        {
            v[nv] = i;
            f[nv] = 0;
            nv++;
            //printf ("- vert %d\n", i);
            if (circ[mp[i]] == 0 && mp[mp[i]] != 0)
            {
                //printf ("- edg %d\n", mp[i]);
                e[mp[i]].push_back(i);
            }
            else if (circ[mp[i]] != 0)
            {
                //printf ("- edg %d\n", circ[mp[i]]);
                e[circ[mp[i]]].push_back(i);
            }
            else
            {
                if (!a[mp[i]])
                {
                    //printf ("- hvert %d\n", mp[i]);
                    a[mp[i]] = 1;
                    v[nv] = mp[i];
                    f[nv] = 1;
                    nv++;
                }
                //printf ("- edg %d\n", mp[i]);
                e[mp[i]].push_back(i);
            }
        }
    }
    for (int i=0; i<nv; i++)
    {
        if (f[i])
        {
            long long mult = dfs(v[i], 1-a[v[i]]);
            ans = ans * mult % MOD;
        }
    }
    printf ("%d\n", (int)ans);
    return 0;
}