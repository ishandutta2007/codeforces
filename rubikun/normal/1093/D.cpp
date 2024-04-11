#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

ll rui(ll a,ll b){
    if(b==1) return a%mod;
    else if(b==0) return 1;
    else if(b%2==0) return (rui(a,b/2)*rui(a,b/2))%mod;
    else return (rui(a,b-1)*a)%mod;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int q=0;q<Q;q++){
        int N,M;cin>>N>>M;
        vector<int> S[N],color(N,0);
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            S[a].push_back(b);
            S[b].push_back(a);
        }
        ll ans=1;
        for(int i=0;i<N;i++){
            if(color[i]) continue;
            int odd=1,even=0;
            color[i]=1;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int a=Q.front();Q.pop();
                for(int j=0;j<S[a].size();j++){
                    int b=S[a][j];
                    if(color[b]==0){
                        color[b]=3-color[a];
                        if(color[b]%2) odd++;
                        else even++;
                        Q.push(b);
                    }else if(color[a]==color[b]){
                        ans=0;
                    }
                }
            }
            ans*=(rui(2,odd)+rui(2,even))%mod;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
}