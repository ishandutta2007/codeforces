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
        vector<int> A(N),ans;
        set<int> SE;
        for(int i=0;i<N;i++){
            cin>>A[i];
            SE.insert(i);
        }
        
        queue<pair<int,int>> Q;
        for(int i=0;i<N;i++){
            if(gcd(A[i],A[(i+1)%N])==1){
                Q.push(mp(i,(i+1)%N));
            }
        }
        
        while(!Q.empty()){
            auto u=Q.front();Q.pop();
            int a=u.fi,b=u.se;
            if(SE.count(a)&&SE.count(b)){
                SE.erase(b);
                ans.push_back(b);
                if(si(SE)==0) break;
                auto it=SE.upper_bound(b);
                if(it==SE.end()) it=SE.begin();
                if(gcd(A[a],A[*it])==1){
                    Q.push(mp(a,*it));
                }
            }
        }
        
        cout<<si(ans)<<" ";
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }
}