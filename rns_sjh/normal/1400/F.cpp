#define USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const double eps = 1e-8;
const int inf = 1e9;
const double dinf = 1e9;
const ll linf = 4e18;
priority_queue<pii> pq;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define vi vector<int>
#define bi bigint
#define fi first
#define se second
#define forl(i, a, b) for(int i = a; i < b; i ++)
#define fore(i, a, b) for(int i = a; i <= b; i ++)
#define rforl(i, a, b) for(int i = a; i > b; i --)
#define rfore(i, a, b) for(int i = a; i >= b; i --)
#define Mod(a, b) ((a % b) + b) % b

#define MX 1010
char s[MX];
int a[110];
int x;

#define N 1010
#define M 5010

string wd[10010];
int link[N * 100], z[N * 100];
ll deg[N * 10];
int n, cnt = 0, pos;
char t[100010];
vector<int> v;
bool vis[M];


struct node{
    int nei[30];
    void clear(){
        memset(nei, -1, sizeof nei);
    }
};

node nd[N * 10];

void build_trie(){
    fore(i, 0, N * 10 - 1) nd[i].clear();
    for(int i = 0; i < n; i ++){
        pos = 0;
        if(nd[0].nei[wd[i][0] - '0'] == -1) nd[0].nei[wd[i][0] - '0'] = ++ cnt, pos = cnt;
        else pos = nd[0].nei[wd[i][0] - '0'];
        for(int j = 1; j < wd[i].size(); j ++){
            if(nd[pos].nei[wd[i][j] - '0'] == -1) nd[pos].nei[wd[i][j] - '0'] = ++ cnt, pos = cnt;
            else pos = nd[pos].nei[wd[i][j] - '0'];
        }
        v.push_back(pos);
        vis[pos] = 1;
    }
}


void cal_link(){
    queue<int> Q;
    link[0] = -1;
    for(int i = 0; i < 30; i ++){
        link[nd[0].nei[i]] = 0;
        if(~nd[0].nei[i]) Q.push(nd[0].nei[i]);
    }
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i = 0; i < 30; i ++){
            if(~nd[u].nei[i]){
                Q.push(nd[u].nei[i]);
                int uu = link[u];
                while(nd[uu].nei[i] == -1){
                    uu = link[uu];
                    if(uu == 0) break;
                }
                link[nd[u].nei[i]] = nd[uu].nei[i];
            }
        }
    }
}
int tot;

void track(int len, int sum){
    if(sum >= x){
        if(x == sum){
            forl(l, 1, len){
                forl(r, l, len){
                    if(l == 1 && r == len - 1) continue;
                    int cnt = 0;
                    fore(i, l, r) cnt += a[i];
                    if(sum % cnt == 0) return;
                }
            }
            string ss; ss.clear();
            forl(i, 1, len) ss += '0' + a[i];
            wd[tot ++] = ss;
        }
        return ;
    }
    fore(i, 1, 9){
        a[len] = i;
        track(len + 1, sum + i);
    }
}


int dp[N][M];

int main(){
    scanf("%s", s + 1);
    scanf("%d", &x);
    track(1, 0);
    n = tot;
    build_trie();
    cal_link();
    int top = cnt;
    int len = strlen(s + 1);
    fore(i, 0, len){
        fore(j, 0, top) dp[i][j] = inf;
    }
    dp[0][0] = 0;
    forl(i, 0, len){
        fore(j, 0, top){
            if(dp[i][j] == inf) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            int cnt = j;
            while(~cnt && nd[cnt].nei[s[i + 1] - '0'] == -1){
                cnt = link[cnt];
            }
            if(~cnt){
                int nx = nd[cnt].nei[s[i + 1] - '0'];
                if(!vis[nx]) dp[i + 1][nx] = min(dp[i + 1][nx], dp[i][j]);
            }
            else{
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][j]);
            }
        }
    }
    int ans = inf;
    fore(j, 0, top) ans = min(ans, dp[len][j]);
    cout << min(ans, len) << endl;

}