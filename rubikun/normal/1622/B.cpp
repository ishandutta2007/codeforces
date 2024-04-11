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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> P(N),pos(N);
        for(int i=0;i<N;i++){
            cin>>P[i];P[i]--;
            pos[P[i]]=i;
        }
        string S;cin>>S;
        int K=0;
        for(int i=0;i<N;i++) K+=1-int(S[i]-'0');
        vector<int> ans(N);
        
        int x=0,y=K;
        for(int i=0;i<N;i++){
            if(S[pos[i]]=='1'){
                ans[pos[i]]=y;
                y++;
            }else{
                ans[pos[i]]=x;
                x++;
            }
        }
        
        for(int i=0;i<N;i++) cout<<ans[i]+1<<" ";
        cout<<"\n";
    }
}