#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--){
        ll N;cin>>N;
        vector<ll> P;
        for(int i=1;i*i<=N;i++){
            if(i*i==N) P.push_back(i);
            else if(N%i==0){
                P.push_back(i);
                P.push_back(N/i);
            }
        }
        
        sort(all(P));
        
        bool ok=false;
        ll a,b,c;
        
        for(int i=1;i<P.size();i++){
            for(int j=i+1;j<P.size();j++){
                if(P[i]*P[j]>N) break;
                for(int k=j+1;k<P.size();k++){
                    if(P[i]*P[j]*P[k]>N) break;
                    if(P[i]*P[j]*P[k]==N){
                        ok=true;
                        a=P[i];
                        b=P[j];
                        c=P[k];
                    }
                }
            }
        }
        
        if(ok){
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}