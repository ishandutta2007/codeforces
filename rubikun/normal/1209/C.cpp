#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N;
        scanf("%d",&N);
        //cin>>N;
        string S;cin>>S;
        vector<int> ans(N,1);
        
        bool ok=false;
        
        int x=0;
        while(!ok&&x<=9){
            ok=true;
            vector<int> ans(N,1);
            for(int i=0;i<N;i++){
                if(S[i]-'0'>=x) ans[i]=2;
            }
            for(int i=N-1;i>=0;i--){
                if(S[i]-'0'==x) ans[i]=1;
                else if(S[i]-'0'<x) break;
            }
            
            int before=-1;
            for(int i=0;i<N;i++){
                if(ans[i]==1){
                    if(S[i]-'0'<before) ok=false;
                    before=S[i]-'0';
                }
            }
            for(int i=0;i<N;i++){
                if(ans[i]==2){
                    if(S[i]-'0'<before) ok=false;
                    before=S[i]-'0';
                }
            }
            
            if(ok){
                for(int i=0;i<N;i++){
                    printf("%d",ans[i]);
                }
                printf("\n");
            }else x++;
        }
        
        if(!ok) printf("-\n");
    }
}