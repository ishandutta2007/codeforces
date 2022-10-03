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
    
    string S;cin>>S;
    int N=S.size();
    vector<vector<int>> cnt(26,vector<int>(N+1));
    
    for(int j=0;j<N;j++){
        cnt[int(S[j]-'a')][j+1]++;
        
        for(int i=0;i<26;i++){
            cnt[i][j+1]+=cnt[i][j];
        }
    }
    
    int Q;cin>>Q;
    
    while(Q--){
        int l,r;cin>>l>>r;
        l--;r--;
        
        if(l==r) cout<<"Yes\n";
        else if(S[l]==S[r]){
            int kind=0;
            for(int i=0;i<26;i++){
                if(cnt[i][r+1]-cnt[i][l]) kind++;
            }
            
            if(kind==1) cout<<"No\n";
            else if(kind==2) cout<<"No\n";
            else if(kind>=3) cout<<"Yes\n";
        }else{
            cout<<"Yes\n";
        }
    }
}