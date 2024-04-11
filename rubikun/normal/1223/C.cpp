#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        Q--;
        
        int N;cin>>N;
        vector<ll> P(N);
        for(int i=0;i<N;i++){
            cin>>P[i];
        }
        sort(all(P));
        reverse(all(P));
        
        ll X,A,Y,B,K;cin>>X>>A>>Y>>B>>K;
        
        ll mid=N;
        ll sum=0;
        
        for(int i=0;i<mid/(A*B/gcd(A,B));i++){
            sum+=P[i]*(X+Y)/100;
        }
        
        if(X>=Y){
            
            for(int i=0;i<mid/A-mid/(A*B/gcd(A,B));i++){
                sum+=P[i+mid/(A*B/gcd(A,B))]*X/100;
            }
            for(int i=0;i<mid/B-mid/(A*B/gcd(A,B));i++){
                sum+=P[i+mid/A]*Y/100;
            }
            
        }else{
            
            for(int i=0;i<mid/B-mid/(A*B/gcd(A,B));i++){
                sum+=P[i+mid/(A*B/gcd(A,B))]*Y/100;
            }
            for(int i=0;i<mid/A-mid/(A*B/gcd(A,B));i++){
                sum+=P[i+mid/B]*X/100;
            }
            
        }
        
        if(sum<K){
            cout<<-1<<endl;
            continue;
        }
        
        ll left=0,right=N;
        
        while(right-left>1){
            ll mid=(left+right)/2;
            ll sum=0;
            
            for(int i=0;i<mid/(A*B/gcd(A,B));i++){
                sum+=P[i]*(X+Y)/100;
            }
            
            if(X>=Y){
                
                for(int i=0;i<mid/A-mid/(A*B/gcd(A,B));i++){
                    sum+=P[i+mid/(A*B/gcd(A,B))]*X/100;
                }
                for(int i=0;i<mid/B-mid/(A*B/gcd(A,B));i++){
                    sum+=P[i+mid/A]*Y/100;
                }
                
            }else{
                
                for(int i=0;i<mid/B-mid/(A*B/gcd(A,B));i++){
                    sum+=P[i+mid/(A*B/gcd(A,B))]*Y/100;
                }
                for(int i=0;i<mid/A-mid/(A*B/gcd(A,B));i++){
                    sum+=P[i+mid/B]*X/100;
                }
                
            }
            
            if(sum<K) left=mid;
            else right=mid;
            
            //cout<<mid<<" "<<sum<<endl;
        }
        
        cout<<right<<endl;
    }
}