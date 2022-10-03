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
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<vector<int>> A(M);
        for(int i=0;i<M;i++){
            int a;cin>>a;
            A[i].resize(a);
            for(int j=0;j<a;j++){
                cin>>A[i][j];
                A[i][j]--;
            }
            sort(all(A[i]));
        }
        
        vector<int> cnt(N),ans(M);
        for(int i=0;i<M;i++) cnt[A[i][0]]++;
        
        pair<int,int> ma=mp(-1,-1);
        
        for(int i=0;i<N;i++) chmax(ma,mp(cnt[i],i));
        
        int lim=(M+1)/2;
        
        for(int i=0;i<M;i++){
            ans[i]=A[i][0];
            if(ma.fi>lim){
                if(A[i][0]==ma.se){
                    if(si(A[i])>=2){
                        ma.fi--;
                        ans[i]=A[i][1];
                    }
                }
            }
        }
        
        if(ma.fi<=lim){
            cout<<"YES\n";
            for(int i=0;i<M;i++) cout<<ans[i]+1<<" ";
            cout<<"\n";
        }else{
            cout<<"NO\n";
        }
        
    }
}