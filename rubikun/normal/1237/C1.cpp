#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<60;

ll dis(ll a,ll b){
    return (b-a)*(b-a);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> X(N),Y(N),Z(N),used(N,0);
    for(int i=0;i<N;i++) cin>>X[i]>>Y[i]>>Z[i];
    
    int Q=N/2;
    while(Q){
        ll mini=INF,point=-1;
        for(int i=0;i<N;i++){
            if(used[i]==0){
                for(int j=0;j<N;j++){
                    if(i!=j&&used[j]==0){
                        if(dis(X[i],X[j])+dis(Y[i],Y[j])+dis(Z[i],Z[j])<mini){
                            mini=dis(X[i],X[j])+dis(Y[i],Y[j])+dis(Z[i],Z[j]);
                            point=j;
                        }
                    }
                }
                cout<<i+1<<" "<<point+1<<endl;
                used[i]=1;
                used[point]=1;
                Q--;
                break;
            }
        }
    }
    
    
}