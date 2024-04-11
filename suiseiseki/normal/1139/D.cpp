#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
const int MAXN = 100005;
int m;
ll F[MAXN], inv[MAXN];
int mu[MAXN], p[MAXN], tot;
bool nprime[MAXN];
struct node{
    int fac, next;
}e[MAXN*100];
int head[MAXN], cnt;
inline void inser(int k, int d){
    e[cnt] = (node){d,head[k]}, head[k] = cnt++;
}
inline void add(int &a, ll b){
    a += b; if(a >= mod) a -= mod;
}
void init(){
    tot = cnt = 0;
    mu[1] = 1;  nprime[0] = nprime[1] = 1;
    for(int i = 2;i<MAXN;i++){
        if(!nprime[i]) mu[i] = -1, p[tot++] = i;
        for(int j = 0;j<tot && i*p[j] < MAXN;j++){
            nprime[i*p[j]] = 1;
            if(i%p[j]==0){
                mu[i*p[j]] = 0;
                break;
            }
            mu[i*p[j]] = -mu[i];
        }
    }
    memset(head, -1, sizeof head);
    for(int i = 2;i<(MAXN>>1);i++)
        for(int j = (i<<1);j<MAXN;j+=i)
            inser(j,i);
	inv[1] = 1;
	for (ll i = 2; i < MAXN; ++i)
        inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
    F[1] = 0;
    for(int i = 2;i <= m;i++){
        int tmp = 0;
        for(int j = head[i];~j;j = e[j].next){
            int d = e[j].fac;
            int x = m/d;
            int tmpp = 1ll*mu[i/d]*(x/(i/d))%mod;
            for(int k = head[i/d];~k;k = e[k].next)
                add(tmpp, 1ll*mu[e[k].fac]*(x/e[k].fac)%mod);
            add(tmpp, x);
            add(tmp, 1ll*tmpp*F[d]%mod);
        }
        add(tmp, m);
        F[i] = 1ll*tmp*inv[m-(m/i)]%mod;
    }
}
int main() {
    scanf("%d",&m);
    init();
    int ans = 0;
    for(int i = 1;i<=m;i++)add(ans,F[i]);
    ans = 1ll*ans*inv[m]%mod;
    add(ans, 1);
    printf("%d\n",ans);
    return 0;
}