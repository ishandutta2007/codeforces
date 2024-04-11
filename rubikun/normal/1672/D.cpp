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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),B(N),keep(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]--;
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
            B[i]--;
        }
        
        bool f=true;
        
        int i=N-1;
        int s=N-1;
        while(i>=0){
            int j=i;
            while(j>=0&&B[j]==B[i]) j--;
            //[j+1,i]
            while(s>=0&&A[s]!=B[i]){
                if(keep[A[s]]==0){
                    f=false;
                    break;
                }else{
                    keep[A[s]]--;
                    s--;
                }
            }
            if(!f) break;
            s--;
            keep[B[i]]+=i-j-1;
            i=j;
        }
        
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}