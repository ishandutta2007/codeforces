#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300005,INF=1<<30;
vector<int> d4a={1,1,2,1,2,3},d4b={2,3,4,4,3,4},d5a={3,3,4,1,2,2,1,1,1,2},d5b={0,4,0,3,4,3,4,0,2,0};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    if(N==1){
        cout<<"YES\n";
        return 0;
    }
    
    if(N%4==0){
        cout<<"YES\n";
        
        for(int i=0;i<N/4;i++){
            for(int j=0;j<6;j++){
                cout<<i*4+d4a[j]<<" "<<i*4+d4b[j]<<"\n";
            }
        }
        
        for(int i=0;i<N/4;i++){
            for(int j=i+1;j<N/4;j++){
                for(int k=0;k<4;k++){
                    cout<<i*4+k+1<<" "<<j*4+k+1<<"\n";
                }
                for(int k=0;k<6;k++){
                    cout<<i*4+d4a[k]<<" "<<j*4+d4b[k]<<"\n";
                    cout<<i*4+d4b[k]<<" "<<j*4+d4a[k]<<"\n";
                }
            }
        }
        
        return 0;
    }
    
    if(N%4==1){
        cout<<"YES\n";
        
        for(int i=0;i<N/4;i++){
            for(int j=0;j<10;j++){
                if(d5b[j]==0) cout<<i*4+d5a[j]<<" "<<N<<"\n";
                else cout<<i*4+d5a[j]<<" "<<i*4+d5b[j]<<"\n";
            }
        }
        
        for(int i=0;i<N/4;i++){
            for(int j=i+1;j<N/4;j++){
                for(int k=0;k<4;k++){
                    cout<<i*4+k+1<<" "<<j*4+k+1<<"\n";
                }
                for(int k=0;k<6;k++){
                    cout<<i*4+d4a[k]<<" "<<j*4+d4b[k]<<"\n";
                    cout<<i*4+d4b[k]<<" "<<j*4+d4a[k]<<"\n";
                }
            }
        }
        
        return 0;
    }
    
    if(N%4==2||N%4==3){
        cout<<"NO\n";
        return 0;
    }
}