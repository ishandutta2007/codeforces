#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

char f(int cnt){
    if(cnt<26) return char('a'+cnt);
    else if(cnt<52) return char('A'+(cnt-26));
    else return char('0'+(cnt-52));
}

int main(){
    
    int Q;cin>>Q;
    while(Q){
        int R,C,K;
        cin>>R>>C>>K;
        int sum=0,cnt=0,now=0;
        vector<string> S(R);
        vector<vector<char>> T(R,vector<char>(C));
        for(int i=0;i<R;i++){
            cin>>S[i];
            
            for(int j=0;j<C;j++){
                if(S[i][j]=='R') sum++;
            }
        }
        int left=K-sum%K;
        
        for(int i=0;i<R;i++){
            if(i%2==0){
                for(int j=0;j<C;j++){
                    T[i][j]=f(now);
                    if(S[i][j]=='R') cnt++;
                    
                    if(now<left&&cnt==sum/K){
                        cnt=0;
                        now++;
                    }else if(now>=left&&cnt==(sum+K-1)/K){
                        cnt=0;
                        now++;
                    }
                    
                    if(now==K) now--;
                }
            }else{
                for(int j=C-1;j>=0;j--){
                    T[i][j]=f(now);
                    if(S[i][j]=='R') cnt++;
                    
                    if(now<left&&cnt==sum/K){
                        cnt=0;
                        now++;
                    }else if(now>=left&&cnt==(sum+K-1)/K){
                        cnt=0;
                        now++;
                    }
                    
                    if(now==K) now--;
                }
            }
        }
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<T[i][j];
            }
            //cout<<endl;
            printf("\n");
        }
        
        Q--;
    }
}