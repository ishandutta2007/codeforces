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
const int mod=998244353,MAX=400005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        pair<int,int> ma=mp(-1,-1);
        for(int i=0;i<N;i++){
            cin>>A[i];
            chmax(ma,mp(A[i],i+1));
        }
        
        if(N==1){
            cout<<0<<"\n";
        }else if(N==2){
            cout<<1<<"\n";
            cout<<"1 2 \n";
            //cout<<"\n";
        }else{
            vector<pair<int,int>> ans;
            if(abs(A[0]-A.back())&1){
                ans.push_back(mp(1,N));
                A[N-1]=A[0];
            }else{
                ans.push_back(mp(1,N));
                A[0]=A[N-1];
            }
            
            for(int i=1;i<N-1;i++){
                if(abs(A[i]-A[0])&1){
                    ans.push_back(mp(1,i+1));
                }else{
                    ans.push_back(mp(i+1,N));
                }
            }
            
            cout<<si(ans)<<"\n";
            for(auto a:ans) cout<<a.fi<<" "<<a.se<<"\n";
        }
    }
}