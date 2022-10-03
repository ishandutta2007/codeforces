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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        
        vector<int> ans(N);
        int now=N;
        
        for(int i=0;i<N-1;i++){
            if(S[i]=='>'){
                ans[i]=now;
                now--;
            }
            if(i==N-2){
                ans[i+1]=now;
                now--;
            }
        }
        
        for(int i=0;i<N;i++){
            if(ans[i]==0){
                int n=i;
                while(n<N&&ans[n]==0){
                    n++;
                }
                n--;
                while(n>=i){
                    ans[n]=now;
                    n--;
                    now--;
                }
            }
        }
        
        for(int i=0;i<N;i++) cout<<ans[i]<<" ";
        cout<<endl;
        
        now=N;
        
        ans.assign(N,0);
        
        for(int i=0;i<N-1;i++){
            if(S[i]=='>'){
                ans[i]=now;
                now--;
                if(i==N-2){
                    ans[i+1]=now;
                    now--;
                }
            }
        }
        
        for(int i=N-1;i>=0;i--) if(ans[i]==0){
            ans[i]=now;
            now--;
        }
        
        for(int i=0;i<N;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}