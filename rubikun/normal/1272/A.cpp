#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll a,b,c;cin>>a>>b>>c;
        vector<int> d={-1,0,1};
        ll ans=INF;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    ll sum=0;
                    sum+=abs(a+d[i]-(b+d[j]));
                    sum+=abs(a+d[i]-(c+d[k]));
                    sum+=abs(b+d[j]-(c+d[k]));
                    
                    ans=min(ans,sum);
                }
            }
        }
        
        cout<<ans<<endl;
    }
}