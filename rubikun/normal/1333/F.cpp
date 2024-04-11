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
    if(N==2){
        cout<<1<<endl;
        return 0;
    }
    if(N==3){
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    
    vector<int> alive(N+1,1),ans(N+1);
    int now=N/2,cnt=N;
    
    while(cnt>=2&&now){
        for(int j=2;now*j<=N;j++){
            if(alive[now*j]){
                alive[now*j]=0;
                cnt--;
            }
        }
        for(int i=cnt+1;i<=N;i++){
            if(ans[i]) break;
            ans[i]=now;
        }
        now--;
    }
    
    for(int i=2;i<=N;i++) cout<<ans[i]<<" ";
    cout<<endl;
    
}