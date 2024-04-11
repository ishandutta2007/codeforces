#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=205,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<int>> S(N,vector<int>(N,-1));
    S[0][0]=1;
    S[0][1]=1;
    S[N-1][N-1]=0;
    int a;
    
    for(int i=0;i<N;i++){
        if(i%2==0){
            for(int j=0;j+2<N;j+=2){
                cout<<"? "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+3<<endl;
                cin>>a;
                if(a==1) S[i][j+2]=S[i][j];
                else S[i][j+2]=1-S[i][j];
            }
            
            if(i!=N-1){
                cout<<"? "<<i+1<<" "<<1<<" "<<i+2<<" "<<2<<endl;
                cin>>a;
                if(a==1) S[i+1][1]=S[i][0];
                else S[i+1][1]=1-S[i][0];
                
                cout<<"? "<<i+1<<" "<<1<<" "<<i+3<<" "<<1<<endl;
                cin>>a;
                if(a==1) S[i+2][0]=S[i][0];
                else S[i+2][0]=1-S[i][0];
            }
        }else{
            for(int j=1;j+2<N;j+=2){
                cout<<"? "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+3<<endl;
                cin>>a;
                if(a==1) S[i][j+2]=S[i][j];
                else S[i][j+2]=1-S[i][j];
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(i%2==0){
            for(int j=1;j+2<N;j+=2){
                cout<<"? "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+3<<endl;
                cin>>a;
                if(a==1) S[i][j+2]=S[i][j];
                else S[i][j+2]=1-S[i][j];
            }
            
            if(i!=N-1){
                cout<<"? "<<i+1<<" "<<2<<" "<<i+2<<" "<<3<<endl;
                cin>>a;
                if(a==1) S[i+1][2]=S[i][1];
                else S[i+1][2]=1-S[i][1];
                
                cout<<"? "<<i+1<<" "<<2<<" "<<i+3<<" "<<2<<endl;
                cin>>a;
                if(a==1) S[i+2][1]=S[i][1];
                else S[i+2][1]=1-S[i][1];
            }
        }else{
            cout<<"? "<<i+1<<" "<<1<<" "<<i+1<<" "<<3<<endl;
            cin>>a;
            if(a==1) S[i][0]=S[i][2];
            else S[i][0]=1-S[i][2];
            for(int j=2;j+2<N;j+=2){
                cout<<"? "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+3<<endl;
                cin>>a;
                if(a==1) S[i][j+2]=S[i][j];
                else S[i][j+2]=1-S[i][j];
            }
        }
    }
    bool did=false;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if((i+j)%2==0) continue;
            
            for(int bit=0;bit<(1<<3);bit++){
                vector<int> h(4),w(4);
                h[0]=i;
                w[0]=j;
                
                for(int k=0;k<3;k++){
                    if(bit&(1<<k)){
                        h[k+1]=h[k]+1;
                        w[k+1]=w[k];
                    }else{
                        h[k+1]=h[k];
                        w[k+1]=w[k]+1;
                    }
                }
                if(h[3]>=N||w[3]>=N) continue;
                
                if(S[h[0]][w[0]]==S[h[2]][w[2]]&&S[h[1]][w[1]]==S[h[3]][w[3]]){
                    did=true;
                    cout<<"? "<<h[0]+1<<" "<<w[0]+1<<" "<<h[3]+1<<" "<<w[3]+1<<endl;
                    cin>>a;
                    
                    if(a==1){
                        if(S[h[0]][w[0]]!=S[h[3]][w[3]]){
                            for(int s=0;s<N;s++){
                                for(int t=0;t<N;t++){
                                    if((s+t)%2==0) continue;
                                    
                                    S[s][t]=1-S[s][t];
                                }
                            }
                        }
                    }else{
                        if(S[h[0]][w[0]]==S[h[3]][w[3]]){
                            for(int s=0;s<N;s++){
                                for(int t=0;t<N;t++){
                                    if((s+t)%2==0) continue;
                                    
                                    S[s][t]=1-S[s][t];
                                }
                            }
                        }
                    }
                }else if(S[h[0]][w[0]]!=S[h[2]][w[2]]&&S[h[1]][w[1]]!=S[h[3]][w[3]]){
                    did=true;
                    cout<<"? "<<h[0]+1<<" "<<w[0]+1<<" "<<h[3]+1<<" "<<w[3]+1<<endl;
                    cin>>a;
                    
                    if(a==1){
                        if(S[h[0]][w[0]]!=S[h[3]][w[3]]){
                            for(int s=0;s<N;s++){
                                for(int t=0;t<N;t++){
                                    if((s+t)%2==0) continue;
                                    
                                    S[s][t]=1-S[s][t];
                                }
                            }
                        }
                    }else{
                        if(S[h[0]][w[0]]==S[h[3]][w[3]]){
                            for(int s=0;s<N;s++){
                                for(int t=0;t<N;t++){
                                    if((s+t)%2==0) continue;
                                    
                                    S[s][t]=1-S[s][t];
                                }
                            }
                        }
                    }
                }
                if(did) break;
            }
            
            if(did) break;
        }
        if(did) break;
    }
    
    //assert(did);
    
    cout<<"!"<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<S[i][j];
        }
        cout<<endl;
    }
    
}