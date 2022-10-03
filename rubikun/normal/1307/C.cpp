#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

ll sum[26][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=S.size();
    ll ans=0;
    
    for(int i=0;i<26;i++){
        for(int j=0;j<N;j++){
            sum[i][j+1]=sum[i][j];
            if(S[j]==char('a'+i)) sum[i][j+1]++;
        }
    }
    
    for(int i=0;i<26;i++){
        ans=max(ans,sum[i][N]);
    }
    
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            ll cnt=0;
            for(int k=0;k<N;k++){
                if(S[k]==char('a'+i)){
                    cnt+=(sum[j][N]-sum[j][k+1]);
                }
            }
            ans=max(ans,cnt);
        }
    }
    
    cout<<ans<<endl;
}