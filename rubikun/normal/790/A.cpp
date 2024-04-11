#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<string> S(N-K+1),ans(N);
    for(int i=0;i<N-K+1;i++) cin>>S[i];
    
    string now="A";
    
    for(int i=0;i<N-K+1;i++){
        if(S[i]=="NO"){
            if(si(ans[i])){
                ans[i+K-1]=ans[i];
            }else{
                ans[i]=now;
                ans[i+K-1]=now;
                now[0]++;
            }
        }
    }
    
    string rem="Aaa";
    
    for(int i=0;i<N;i++){
        if(si(ans[i])==0){
            ans[i]=rem;
            if(rem[1]!='z') rem[1]++;
            else rem[2]++;
        }
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}