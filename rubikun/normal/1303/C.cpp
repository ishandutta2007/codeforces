#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        if(S.size()==1){
            cout<<"YES"<<endl;
            cout<<S[0];
            for(int i=0;i<26;i++){
                if(S[0]==char('a'+i)) continue;
                cout<<char('a'+i);
            }
            cout<<endl;
            continue;
        }
        vector<set<char>> cn(26);
        for(int i=1;i<S.size();i++){
            cn[S[i-1]-'a'].insert(S[i]);
            cn[S[i]-'a'].insert(S[i-1]);
        }
        int ok=0;
        for(int i=0;i<26;i++){
            if(cn[i].size()==1) ok++;
            if(cn[i].size()>=3) ok=-1000;
        }
        
        if(ok!=2){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        string ans;
        vector<int> done(26);
        
        for(int i=0;i<26;i++){
            if(cn[i].size()==1){
                ans+=char('a'+i);
                done[i]=1;
                break;
            }
        }
        
        while(1){
            bool q=false;
            for(int i=0;i<26;i++){
                if(cn[ans.back()-'a'].find(char('a'+i))!=cn[ans.back()-'a'].end()){
                    if(done[i]==0){
                        ans+=char('a'+i);
                        done[i]=1;
                        q=1;
                        break;
                    }
                }
            }
            if(!q) break;
        }
        
        for(int i=0;i<26;i++){
            if(done[i]==0) ans+=char('a'+i);
        }
        
        cout<<ans<<endl;
    }
}