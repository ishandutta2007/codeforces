#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=4005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--){
        int N;
        ll S;cin>>N>>S;
        
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        ll sum=0;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
            
            if(sum>S){
                ll maxi=-1,point=-1;
                for(int j=0;j<=i;j++){
                    if(maxi<A[j]){
                        maxi=A[j];
                        point=j;
                    }
                }
                cout<<point+1<<endl;
                break;
            }
        }
        
        if(sum<=S) cout<<0<<endl;
    }
}