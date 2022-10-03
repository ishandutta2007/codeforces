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
    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<pair<int,int>> P(N);
        for(int i=0;i<N;i++){
            cin>>P[i].first>>P[i].second;
        }
        bool ok=true;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(P[i].first<P[j].first&&P[i].second>P[j].second) ok=false;
            }
        }
        
        if(!ok){
            cout<<"NO"<<endl;
            continue;
        }
        
        cout<<"YES"<<endl;
        
        sort(all(P));
        
        string ans;
        int xnow=0,ynow=0;
        
        for(int i=0;i<N;i++){
            for(int j=xnow;j<P[i].first;j++) ans+='R';
            for(int j=ynow;j<P[i].second;j++) ans+='U';
            
            xnow=P[i].first;
            ynow=P[i].second;
        }
        
        cout<<ans<<endl;
        
    }
}