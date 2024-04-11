#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

int main(){
    
    int Q;cin>>Q;
    vector<int> beki(30,1);
    for(int i=1;i<30;i++) beki[i]=beki[i-1]*2;
    for(int i=0;i<30;i++) beki[i]--;
    while(Q){
        int A;cin>>A;
        for(int i=0;i<30;i++){
            if(A==beki[i]){
                bool ok=false;
                for(int k=2;k*k<=beki[i];k++){
                    if(beki[i]%k==0){
                        cout<<beki[i]/k<<endl;
                        ok=true;
                    }
                    if(ok) break;
                }
                if(!ok) cout<<1<<endl;
                break;
            }else if(A<beki[i]){
                cout<<beki[i]<<endl;
                break;
            }
        }
        
        Q--;
    }
}