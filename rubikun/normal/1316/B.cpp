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
        pair<string,int> ans={"{",0};
        
        for(int i=1;i<=N;i++){
            if((N-i)%2==1){
                string T=S.substr(i-1)+S.substr(0,i-1);
                ans=min(ans,{T,i});
            }else{
                string U=S.substr(0,i-1);
                reverse(all(U));
                string T=S.substr(i-1)+U;
                ans=min(ans,{T,i});
            }
        }
        
        cout<<ans.first<<endl;
        cout<<ans.second<<endl;
    }
}