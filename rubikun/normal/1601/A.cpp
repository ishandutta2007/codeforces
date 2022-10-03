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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

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
        int g=0;
        for(int k=0;k<30;k++){
            int cnt=0;
            for(int i=0;i<N;i++) if(A[i]&(1<<k)) cnt++;
            g=gcd(g,cnt);
        }
        if(g==0){
            for(int i=1;i<=N;i++) cout<<i<<" ";
            cout<<"\n";
        }else{
            vector<int> ans;
            for(int i=1;i*i<=g;i++){
                if(g%i==0){
                    ans.push_back(i);
                    if(i*i!=g) ans.push_back(g/i);
                }
            }
            sort(all(ans));
            for(int a:ans) cout<<a<<" ";
            cout<<"\n";
        }
    }
}