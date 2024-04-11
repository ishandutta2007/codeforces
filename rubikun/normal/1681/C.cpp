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
const int mod=998244353,MAX=105,INF=1<<30;

bool dp[MAX][2][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        
        vector<pair<int,int>> ans;
        for(int t=0;t<N;t++){
            pair<int,int> mi=mp(INF,INF);
            for(int i=t;i<N;i++){
                chmin(mi,mp(A[i],i));
            }
            if(mi.se!=t){
                ans.push_back(mp(mi.se,t));
                swap(A[mi.se],A[t]);
                swap(B[mi.se],B[t]);
            }
        }
        int i=0;
        while(i<N){
            int j=i;
            while(j<N&&A[i]==A[j]) j++;
            for(int t=i;t<j;t++){
                pair<int,int> mi=mp(INF,INF);
                for(int k=t;k<j;k++){
                    chmin(mi,mp(B[k],k));
                }
                if(mi.se!=t){
                    ans.push_back(mp(mi.se,t));
                    swap(A[mi.se],A[t]);
                    swap(B[mi.se],B[t]);
                }
            }
            i=j;
        }
        
        bool f=true;
        for(int i=0;i+1<N;i++) f&=(A[i]<=A[i+1]);
        for(int i=0;i+1<N;i++) f&=(B[i]<=B[i+1]);
        
        if(f){
            cout<<si(ans)<<"\n";
            for(auto x:ans) cout<<x.fi+1<<" "<<x.se+1<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}