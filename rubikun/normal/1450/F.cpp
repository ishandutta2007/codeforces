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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),cn(N);
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]--;
            cn[A[i]]++;
        }
        sort(all(cn));
        if(cn.back()>(N+1)/2){
            cout<<-1<<"\n";
            continue;
        }
        
        vector<pair<int,int>> S;
        int l=0;
        while(l<N){
            
            int r=l;
            while(r+1<N&&A[r]!=A[r+1]){
                r++;
            }
            
            if(r==N-1){
                S.push_back(mp(A[l],A[r]));
                break;
            }
            
            S.push_back(mp(A[l],A[r]));
            l=r+1;
        }
        
        vector<pair<int,int>> cnt(N);
        
        for(int i=0;i<N;i++) cnt[i].se=i;
        
        for(auto x:S){
            if(x.fi==x.se){
                cnt[x.fi].fi++;
                sum++;
            }
        }
        
        sort(all(cnt));
        
        int sum2=0;
        
        for(auto x:S){
            if(x.fi!=x.se&&x.fi!=cnt.back().se&&x.se!=cnt.back().se) sum2++;
        }
        
        int K=2*cnt.back().fi-sum-sum2;
        if(K<1) K=1;
        cout<<si(S)-1+(K-1)<<"\n";
    }
}