#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define MAX_N 200000

vector<int> v[MAX_N+1];
int N, M, K;
char c[MAX_N+1][30];
string str[MAX_N+1];
map <string, int> mp;
int arr[MAX_N+1];
int group[MAX_N+1];

long long sum;

bool sf(int x, int y)
{
    return arr[x]<arr[y];
}



int main()
{
    scanf("%d%d%d", &N, &K, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%s", c[i]);
        str[i] = c[i];
        mp.insert({str[i], i});
    }
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<=K; i++)
    {
        int t, x;
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d", &x);
            group[x]=i;
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end(), sf);
    }
    string str2;
    for(int i=1; i<=M; i++)
    {
        scanf("%s", c[i]);
        str2=c[i];
        sum+=(long long)arr[v[group[mp.find(str2)->second]].front()];
    }
    printf("%lld", sum);
    return 0;
}