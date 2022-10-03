#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> deta(N),ans(N);
        int cn=0;
        for(int t=0;t<N;t++){
            if(deta[t]) continue;
            vector<int> res;
            while(1){
                cout<<"? "<<t+1<<endl;
                int x;cin>>x;x--;
                if(si(res)&&res[0]==x) break;
                else res.push_back(x);
            }
            
            if(si(res)==1){
                ans[t]=t;
            }else{
                for(int i=0;i<si(res);i++){
                    if((cn+i)%si(res)==1){
                        
                        for(int j=0;j<si(res);j++){
                            ans[res[(i+j)%si(res)]]=res[(i+j+1)%si(res)];
                        }
                        
                        break;
                    }
                }
            }
            
            
            cn+=si(res)+1;
            for(int a:res) deta[a]=true;
        }
        
        cout<<"!";
        for(int i=0;i<N;i++) cout<<" "<<ans[i]+1;
        cout<<endl;
    }
}