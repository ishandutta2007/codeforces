#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        string S;cin>>S;
        S+='!';
        
        vector<int> cnt(26,0);
        
        int now=1;
        
        for(int i=1;i<S.size();i++){
            if(S[i]!=S[i-1]){
                if(now%2==1){
                    cnt[S[i-1]-'a']++;
                }
                now=1;
            }else now++;
        }
        
        for(int i=0;i<26;i++){
            if(cnt[i]>=1) cout<<char('a'+i);
        }
        cout<<endl;
        
        T--;
        
    }
    
}