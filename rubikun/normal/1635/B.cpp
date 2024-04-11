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
const int mod=998244353,MAX=300005;
const int INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        vector<int> S;
        for(int i=1;i+1<N;i++){
            if(A[i]>A[i-1]&&A[i]>A[i+1]) S.push_back(i);
        }
        int ans=0;
        for(int i=0;i<si(S);){
            if(i+1<si(S)&&S[i]+2==S[i+1]){
                int a=S[i]+1,b=max(A[S[i]],A[S[i]+2]);
                A[a]=b;
                ans++;
                i+=2;
            }else{
                int a=S[i]+1,b=A[S[i]];
                A[a]=b;
                ans++;
                i++;
            }
        }
        cout<<ans<<"\n";
        for(int a:A) cout<<a<<" ";
        cout<<"\n";
    }
}