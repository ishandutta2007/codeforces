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
    
    int Q;cin>>Q;
    while(Q--){
        int H,N;cin>>H>>N;
        set<int> SE;
        for(int i=0;i<N;i++){
            int a;cin>>a;
            SE.insert(a);
        }
        SE.insert(0);
        SE.insert(-1);
        SE.insert(-2);
        
        int ans=0,now=H;
        
        while(now>0){
            if(SE.count(now-1)){
                if(SE.count(now-2)){
                    now-=2;
                }else{
                    ans++;
                    now-=2;
                }
            }else now--;
            
            auto it=SE.lower_bound(now);
            it--;
            now=*it+1;
        }
        
        cout<<ans<<endl;
    }

}