#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    char la;
    
    cout<<N*M*2<<endl;
    
    for(int i=0;i<M;i++){
        if(i%2==0){
            for(int j=0;j<N-1;j++){
                cout<<'U';
                la='U';
            }
        }else{
            for(int j=0;j<N-1;j++){
                cout<<'D';
                la='D';
            }
        }
        cout<<'R';
    }
    
    if(la=='U'){
        for(int i=0;i<M;i++){
            if(i%2==1){
                for(int j=0;j<N-1;j++){
                    cout<<'U';
                    la='U';
                }
            }else{
                for(int j=0;j<N-1;j++){
                    cout<<'D';
                    la='D';
                }
            }
            cout<<'L';
        }
    }else{
        for(int i=0;i<M;i++){
            if(i%2==0){
                for(int j=0;j<N-1;j++){
                    cout<<'U';
                    la='U';
                }
            }else{
                for(int j=0;j<N-1;j++){
                    cout<<'D';
                    la='D';
                }
            }
            cout<<'L';
        }
    }
    cout<<endl;
}