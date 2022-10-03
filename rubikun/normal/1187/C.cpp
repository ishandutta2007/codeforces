#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> Q;
    vector<int> S(N-1,0);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        b--;c--;
        if(a==0) Q.push_back(make_pair(b,c));
        else{
            for(int j=b;j<c;j++){
                S[j]++;
            }
        }
    }
    
    bool ok=true;
    
    for(int i=0;i<Q.size();i++){
        bool check=false;
        int a=Q[i].first,b=Q[i].second;
        for(int j=a;j<b;j++){
            if(S[j]==0) check=true;
        }
        if(!check) ok=false;
    }
    
    if(ok){
        cout<<"YES"<<endl;
        vector<int> ans(N,10000);
        for(int i=0;i<N-1;i++){
            if(S[i]) ans[i+1]=10000;
            else ans[i+1]=ans[i]-1;
        }
        for(int i=0;i<N;i++){
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }else cout<<"NO"<<endl;
    
}