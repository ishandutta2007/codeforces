#include <iostream>
#include <bitset>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,f,sg[N],b[N],w[N],r[N];
bitset<N> S[102], P; 

int prime[N],vis[N];

int main(){
    for(int i=2;i<N;i++){
        if(vis[i]==0) prime[++prime[0]]=i;
        for(int j=i+i;j<N;j+=i){
            vis[j]=1;
        }
    }
    for(int i=1;i<=prime[0];i++){
        P[prime[i]]=1;
        for(int j=1;j<=prime[0];j++){
            if((LL)prime[i]*prime[j]>=N) break;
            P[prime[i]*prime[j]]=1;
        }
    }
    scanf("%d%d",&n,&f); P[f]=0;
    
    S[0]=P;
    for(int i=1;i<N;i++) {
        while(S[sg[i]][i]) sg[i]++;
        S[sg[i]] |= P<<i;
    }

    int ans=0; 
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&b[i],&w[i],&r[i]);
        ans = ans ^ sg[w[i]-b[i]-1];
        ans = ans ^ sg[r[i]-w[i]-1];
    }
    if(ans) printf("Alice\nBob\n"); else printf("Bob\nAlice\n");
}