#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> x={1,8,9,14,2,7,15,10,3,6,11,13,4,5,12,16};
vector<int> y={1,2,3,4,5,25,21,14,13,6,22,20,15,12,7,19,24,16,11,8,23,18,17,10,9};
vector<int> dh={1,0,-1,0},dw={0,1,0,-1};
vector<int> dh2={1,1,1,0,-1,-1,-1,0},dw2={1,0,-1,-1,-1,0,1,1};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    if(N==1||N==2){
        cout<<-1<<endl;
        return 0;
    }
    if(N==3){
        cout<<"1 2 6\n";
        cout<<"3 5 8\n";
        cout<<"9 4 7\n";
        return 0;
    }
    
    vector<vector<int>> S(N,vector<int>(N));
    
    if(N%2==0){
        int a=N/2-2;
        for(int i=0;i<16;i++){
            S[a+i/4][a+i%4]=N*N-16+x[i];
        }
        
        int h=0,w=0,now=1,k=0;
        
        while(S[h][w]==0){
            S[h][w]=now;
            if(0<=h+dh[k]&&h+dh[k]<N&&0<=w+dw[k]&&w+dw[k]<N&&S[h+dh[k]][w+dw[k]]==0){
                h+=dh[k];
                w+=dw[k];
            }else{
                k++;
                k%=4;
                h+=dh[k];
                w+=dw[k];
            }
            now++;
        }
    }else{
        int a=N/2-2;
        for(int i=0;i<25;i++){
            S[a+i/5][a+i%5]=N*N-25+y[i];
        }
        
        int h=0,w=0,now=1,k=0;
        
        while(S[h][w]==0){
            S[h][w]=now;
            if(0<=h+dh[k]&&h+dh[k]<N&&0<=w+dw[k]&&w+dw[k]<N&&S[h+dh[k]][w+dw[k]]==0){
                h+=dh[k];
                w+=dw[k];
            }else{
                k++;
                k%=4;
                h+=dh[k];
                w+=dw[k];
            }
            now++;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
}