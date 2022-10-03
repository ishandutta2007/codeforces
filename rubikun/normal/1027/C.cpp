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
    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> cnt(10003);
        vector<int> use;
        int ans=-1;
        
        for(int i=0;i<N;i++){
            int a;cin>>a;
            cnt[a]++;
            if(cnt[a]==2) use.push_back(a);
            if(cnt[a]==4) ans=a;
        }
        
        if(ans!=-1){
            cout<<ans<<" "<<ans<<" "<<ans<<" "<<ans<<endl;
        }else{
            sort(all(use));
            
            double mini=INF;
            pair<int,int> ans={-1,-1};
            
            for(int i=0;i+1<use.size();i++){
                if(mini>double(use[i+1])/double(use[i])){
                    mini=double(use[i+1])/double(use[i]);
                    ans={use[i],use[i+1]};
                }
            }
            
            cout<<ans.first<<" "<<ans.first<<" "<<ans.second<<" "<<ans.second<<endl;
        }
    }
}