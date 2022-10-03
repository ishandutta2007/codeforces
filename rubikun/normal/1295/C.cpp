#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        string S,T;cin>>S>>T;
        vector<int> when[26];
        for(int i=0;i<S.size();i++){
            when[S[i]-'a'].push_back(i);
        }
        bool ok=true;
        ll cnt=-1;
        
        for(int i=0;i<T.size();i++){
            int a=T[i]-'a';
            if(when[a].size()==0){
                ok=false;
                break;
            }
            auto it=upper_bound(all(when[a]),cnt%ll(S.size()));
            if(it==when[a].end()){
                int b=when[a][0];
                cnt=(cnt/ll(S.size())+1)*ll(S.size())+b;
            }else{
                cnt=cnt/ll(S.size())*ll(S.size())+*it;
            }
        }
        
        if(ok) cout<<(cnt+1+S.size()-1)/(S.size())<<endl;
        else cout<<-1<<endl;
    }
}