#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;

#define MOD 1000000007


int mx[1024][1024];
int two[1024];
vector<int> v;
int N;

void input()
{
int i, m, x;
scanf("%d%d", &N, &m);
for(i = 0; i < m; i++)
    {
    scanf("%d", &x);
    v.push_back(x);
    }

sort(v.begin(), v.end());
}

void prepare()
{
int i, j;
mx[0][0] = 1;
for(i = 1; i < 1024; i++)
    {
    mx[i][0] = mx[i][i] = 1;
    for(j = 1; j < i; j++)
        mx[i][j] = (mx[i-1][j] + mx[i-1][j-1]) % MOD;
    }
two[0] = 1;
for(i = 1; i < 1024; i++) two[i] = (2*two[i-1]) % MOD;
}



void solve()
{


int i, k, lamps = 0;
unsigned long long F = 1;

for(i = 1; i < v.size(); i++)
    {
    k = v[i] - v[i-1] - 1;
    if(k == 0) continue;
    F = (F*mx[k+lamps][k]) % MOD;
    F = (F*two[k-1]) % MOD;
    lamps += k;
    }

k = v[0] - 1;
if(k != 0)
    {
    F = (F*mx[k+lamps][k]) % MOD;
    lamps += k;
    }

k = N - v[v.size()-1];
if(k != 0)
    F = (F*mx[k+lamps][k]) % MOD;

printf("%d\n", F);
}

int main()
{
input();
prepare();
solve();

return 0;
}