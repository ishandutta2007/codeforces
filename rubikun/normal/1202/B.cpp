#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=int(S.size());
    
    int T[10][10][10];
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                int mini=INF;
                for(int x=0;x<10;x++){
                    for(int y=0;y<10;y++){
                        if((j*x+k*y)%10==i&&(x+y)) mini=min(mini,x+y);
                    }
                }
                if(mini==INF){
                    T[i][j][k]=-1;
                }else{
                    T[i][j][k]=mini-1;
                }
            }
        }
    }
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(j) cout<<" ";
            int sum=0;
            for(int k=1;k<N;k++){
                int d=(S[k]-S[k-1]+10)%10;
                if(T[d][i][j]==-1){
                    sum=-1;
                    break;
                }else sum+=T[d][i][j];
            }
            cout<<sum;
        }
        cout<<endl;
    }
}