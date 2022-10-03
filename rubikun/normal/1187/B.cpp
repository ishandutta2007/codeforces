#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    vector<vector<int>> cnt(26,vector<int>(N+1,0));
    for(int i=1;i<=N;i++){
        for(int j=0;j<26;j++){
            cnt[j][i]=cnt[j][i-1];
        }
        cnt[S[i-1]-'a'][i]++;
    }
    int M;cin>>M;
    for(int k=0;k<M;k++){
        string T;cin>>T;
        vector<int> cc(26,0);
        for(int i=0;i<T.size();i++){
            cc[T[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            auto it=lower_bound(all(cnt[i]),cc[i]);
            ans=max(int(distance(cnt[i].begin(),it)),ans);
        }
        
        cout<<ans<<endl;
    }
}