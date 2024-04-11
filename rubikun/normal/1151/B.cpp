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
    
    int N,M;cin>>N>>M;
    vector<vector<int>> S(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>S[i][j];
        }
    }
    
    bool ok=false;
    pair<int,int> use={-1,-1};
    
    for(int i=0;i<N;i++){
        for(int j=1;j<M;j++){
            if(S[i][0]!=S[i][j]){
                ok=true;
                use={i,j};
            }
        }
    }
    
    if(ok){
        cout<<"TAK"<<endl;
        int x=0;
        for(int i=0;i<N;i++){
            x^=S[i][0];
        }
        if(x!=0){
            for(int i=0;i<N;i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }else{
            for(int i=0;i<N;i++){
                if(i==use.first) cout<<use.second+1<<" ";
                else cout<<1<<" ";
            }
            cout<<endl;
        }
    }else{
        int x=0;
        for(int i=0;i<N;i++){
            x^=S[i][0];
        }
        
        if(x!=0){
            cout<<"TAK"<<endl;
            for(int i=0;i<N;i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
    }
}