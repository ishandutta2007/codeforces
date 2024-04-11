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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int l,r;cin>>l>>r;
        int N=r+1;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int ans=0;
        for(int k=16;k>=0;k--){
            int a=0,b=0;
            for(int i=0;i<si(A);i++){
                if(A[i]&(1<<k)) a++;
                else b++;
            }
            if(a==b){
                sort(all(A));
                for(int i=0;i<b;i++) A.pop_back();
            }else if(a>b){
                ans^=(1<<k);
                sort(all(A));
                if(b) for(int i=0;i<a;i++) A.pop_back();
            }else{
                sort(all(A));
                reverse(all(A));
                if(a) for(int i=0;i<b;i++) A.pop_back();
            }
        }
        cout<<ans<<"\n";
    }
}