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
    int diff=0;
    set<pair<int,int>> SE;
    int left=-INF,right=INF;
    bool ok=true;
    for(int i=0;i<N;i++){
        int c,d;cin>>c>>d;
        if(d==1){
            int lcan=1900-diff,rcan=INF;
            if(right<lcan) ok=false;
            
            left=max(left,lcan);
            right=min(right,rcan);
        }else{
            int lcan=-INF,rcan=1899-diff;
            if(rcan<left) ok=false;
            
            left=max(left,lcan);
            right=min(right,rcan);
        }
        
        diff+=c;
    }
    
    if(!ok) cout<<"Impossible"<<endl;
    else if(right==INF) cout<<"Infinity"<<endl;
    else cout<<right+diff<<endl;
}