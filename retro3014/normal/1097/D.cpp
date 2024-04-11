#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define DIV 1000000007LL
typedef long long ll;
#define MAX_K 1000

ll N, K;
vector<ll> p;
vector<ll> d;
ll ans=0;


ll multi(ll a, ll b){
    if(b==0)    return 1;
    if(b==1)    return a%DIV;
    ll m=multi(a, b/2);
    if(b%2==0){
        return (m*m)%DIV;
    }else{
        return ((m*m%DIV)*a)%DIV;
    }
}

ll inv(ll a){
    return multi(a, DIV-2);
}

ll comb=1;
ll pac[MAX_K*3+1];
ll cp=0;


ll arr[30][60], arr2[30][60];
ll now=1;
ll t=1;

ll cp2=0;

void dfs(int x){
    if(x==d.size()){
        if(cp==0 && cp2==0)   ans=(ans+now*t)%DIV;
        return;
    }else{
        for(int i=0; i<=d[x]; i++){
            if(arr[x][i]==0)  cp2++;
            else    t=(t*arr[x][i])%DIV;
            dfs(x+1);
            if(p[x]==0) {cp--;}
            else now=(now*inv(p[x])%DIV);
            if(arr[x][i]==0)  cp2--;
            else t=(t*inv(arr[x][i]))%DIV;
        }
        for(int i=0; i<=d[x]; i++){
            if(p[x]==0)   {cp++;}
            else    now=(now*p[x]%DIV);
        }
    }
}

int main(){
    scanf("%lld%lld", &N, &K);
    ll M = N;
    ll pi=2, cnt=0;
    while(pi*pi<=N){
        if(N%pi==0){
            cnt=0;
            while(N%pi==0){
                N/=pi; cnt++;
            }
            p.push_back(pi%DIV);
            d.push_back(cnt);
        }
        pi++;
    }
    if(N!=1)    {d.push_back(1); p.push_back(N%DIV);}
    now = N = M;
    if(N%DIV==0){
        cp=1;
        now=now/DIV;
    }else now=now%DIV;
    for(int i=0; i<d.size(); i++){
        for(int j=0; j<=d[i]; j++){
            arr[i][j] = arr2[i][j]=0;
        }
        arr[i][0]=1;
        for(int k=1; k<=K; k++){
            for(int j=0; j<=d[i]; j++){
                arr[i][j]=(arr[i][j]*inv(d[i]-j+1))%DIV;
                for(int t=j; t<=d[i]; t++){
                    arr2[i][t]=(arr2[i][t]+arr[i][j])%DIV;
                }
            }
            for(int j=0; j<=d[i]; j++){
                arr[i][j]=arr2[i][j]; arr2[i][j]=0;
            }
        }
    }
    dfs(0);
    printf("%lld", ans);
    return 0;
}