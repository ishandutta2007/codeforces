#include <iostream>
#include <vector>
using namespace std;
const int N=500000+10;
typedef long long LL;
int prime[N], cnt = 0;
bool vis[N]; 
int phi[N], mius[N];

void getPrime() {
    phi[1] = 1, mius[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (vis[i] == 0) {
            prime[++ cnt] = i;
            phi[i] = i - 1;
            mius[i] = -1;
        }
        for (int j = 1; j <= cnt && prime[j] * i < N; j ++) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) {           
                mius[prime[j] * i] = 0;
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            } else {
                mius[prime[j] * i] = mius[i] * -1;
                phi[prime[j] * i] = phi[i] * (prime[j] - 1);
            }
        }
    }

}
vector<int> f[N];
int c[N],n,m,a[N],v[N];
int main(){

    getPrime();
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            f[j].push_back(i);
        }
    }

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    LL ans=0;
    for(int i=1;i<=m;i++){
        int x; scanf("%d",&x);
        if(v[x]==0){
            v[x]=1;
            for(auto p: f[a[x]]){
                ans -= mius[p] * (LL)c[p] * (c[p]-1) / 2;
                c[p] ++;
                ans += mius[p] * (LL)c[p] * (c[p]-1) / 2;
            }
        } else {
            v[x]=0;
            for(auto p: f[a[x]]){
                ans -= mius[p] * (LL)c[p] * (c[p]-1) / 2;
                c[p] --;
                ans += mius[p] * (LL)c[p] * (c[p]-1) / 2;
            }
        }
        printf("%lld\n", ans);
    }
}