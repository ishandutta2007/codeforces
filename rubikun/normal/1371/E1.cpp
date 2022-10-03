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
    
    int N,P;cin>>N>>P;
    vector<int> A(N),cnt(4001);
    for(int i=0;i<N;i++){
        cin>>A[i];
        cnt[A[i]]++;
    }
    for(int i=1;i<=4000;i++) cnt[i]+=cnt[i-1];
    
    sort(all(A));
    
    vector<int> ans;
    for(int i=1;i<=2000;i++){
        int now=1;
        bool ok=true;
        for(int j=0;j<N;j++){
            if(cnt[i+j]<(j+1)) ok=false;
            else{
                now*=(cnt[i+j]-j);
                now%=P;
                if(now==0) ok=false;
            }
        }
        if(ok) ans.push_back(i);
    }
    
    cout<<si(ans)<<"\n";
    for(int a:ans) cout<<a<<" ";
    cout<<"\n";
}