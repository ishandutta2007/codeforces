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
    vector<string> S(N);
    vector<int> ok(N);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    
    string ans="",plus="";
    
    for(int i=0;i<N;i++){
        if(ok[i]) continue;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            reverse(all(S[j]));
            if(S[i]==S[j]){
                reverse(all(S[j]));
                ok[i]=1;
                ok[j]=1;
                ans+=S[i];
                break;
            }else{
                reverse(all(S[j]));
            }
        }
        if(ok[i]) continue;
        
        bool can=true;
        
        for(int j=0;j<M;j++){
            if(S[i][j]!=S[i][M-1-j]) can=false;
        }
        
        if(can) plus=S[i];
    }
    
    string ret="";
    ret+=ans;
    ret+=plus;
    reverse(all(ans));
    ret+=ans;
    
    cout<<int(ret.size())<<endl;
    cout<<ret<<endl;
}