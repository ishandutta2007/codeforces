#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef long long LL;
const int N=7000+10;
int prime[N], cnt = 0;
bool vis[N]; 
int phi[N], mius[N];
vector<int> f[N];
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
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i)
            f[j].push_back(i);
    }
}


int n,q;
bitset<N> st[100000+10],bu[100000+10];

vector<int> M;
int main(){
    getPrime();
    for(int i=1;i<N;i++) 
        if(mius[i]) M.push_back(i);
    for(int i=1;i<N;i++){
        for(int j=0;j<M.size() && M[j]*i<N; j++){
            bu[i][M[j]*i-1]=1;
        }
    }
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
        int op,x,y,z; scanf("%d%d%d",&op,&x,&y);
        if(op==1) {
            st[x].reset();
            for(auto d: f[y]) {
                st[x][d-1]=1;
            }
        }
        if(op==2){
            scanf("%d",&z);
            st[x] = (st[y] ^ st[z]);
        }
        if(op==3){
            scanf("%d",&z);
            st[x] = (st[y] & st[z]);
        }
        if(op==4){
            int sum = (st[x] & bu[y]).count();
            printf("%d", sum%2);
        }
        //prt(st[x]);
    }
}