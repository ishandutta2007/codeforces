#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 100004;

int a[MAXN];
vector<int> ans;
int pre[30];
pair<int, int> q;

int main()
{
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif
    int n;
    int i, j, k;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    memset(pre, 1, sizeof pre);
    for(i = n-1; i >= 0; i--){
        for(j = 0; j < 25; j++)
            if(a[i]&1<<j)
                pre[j] = i;
        for(j = 0; j < 25; j++){
            if(pre[j] < n){
                int t = 0;
                for(k = 0; k < 25; k++)
                    if(pre[k] <= pre[j])
                        t |= 1<<k;
                ans.pb(t);
            }
        }
        ans.pb(a[i]);
    }
    sort(ans.begin(), ans.end());
    cout<<(unique(ans.begin(), ans.end())-ans.begin())<<endl;;
    return 0;
}