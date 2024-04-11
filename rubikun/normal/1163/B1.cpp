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
    
    int N;cin>>N;
    vector<int> A(N),cnt(100005,0);
    for(int i=0;i<N;i++) cin>>A[i];
    
    set<pair<int,int>> SE;//
    
    int ans=0;
    
    for(int i=0;i<N;i++){
        if(cnt[A[i]]==0){
            SE.insert({1,A[i]});
            cnt[A[i]]++;
        }else{
            SE.erase({cnt[A[i]],A[i]});
            SE.insert({cnt[A[i]]+1,A[i]});
            cnt[A[i]]++;
        }
        
        if(SE.size()==1) ans=max(ans,i+1);
        else if(SE.size()==2){
            auto left=SE.begin(),right=left;
            right++;
            if((*left).first+1==(*right).first) ans=max(ans,i+1);
            if((*left).first==1) ans=max(ans,i+1);
        }else{
            auto left=SE.begin(),left2=left,right=SE.end(),right2=right;
            right--;
            right2--;
            right2--;
            left2++;
            if((*left).first==1){
                if((*left2).first==(*right).first) ans=max(ans,i+1);
            }
            
            if((*right2).first==(*left).first&&(*right2).first+1==(*right).first) ans=max(ans,i+1);
            
            //cout<<i<<" "<<(*right).second<<endl;
        }
    }
    
    cout<<ans<<endl;
}