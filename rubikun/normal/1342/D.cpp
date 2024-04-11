#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<int> A(N),B(K);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]--;
    }
    sort(all(A));
    for(int i=0;i<K;i++) cin>>B[i];
    
    int left=0,right=N;
    while(right-left>1){
        int mid=(left+right)/2;
        vector<vector<int>> S(mid,vector<int>());
        
        for(int i=0;i<N;i++){
            S[i%mid].push_back(A[i]);
        }
        bool ok=true;
        
        for(int i=0;i<mid;i++){
            for(int j=0;j<si(S[i]);j++){
                if(si(S[i])-j>B[S[i][j]]) ok=false;
            }
        }
        if(ok) right=mid;
        else left=mid;
    }
    cout<<right<<endl;
    
    int mid=right;
    
    vector<vector<int>> S(mid,vector<int>());
    
    for(int i=0;i<N;i++){
        S[i%mid].push_back(A[i]);
    }
    
    for(int i=0;i<mid;i++){
        cout<<si(S[i])<<" ";
        for(int j:S[i]) cout<<j+1<<" ";
        cout<<"\n";
    }
}