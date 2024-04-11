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
const int mod=1000000007,MAX=200005;
const int INF=1<<30;
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    vector<vector<int>> ans;
    
    while(1){
        bool ok=true;
        for(int i=0;i<N;i++) if(A[i]!=i+1) ok=false;
        if(ok) break;
        
        for(int i=1;i+1<=N;i++){
            int a,b;
            for(int j=0;j<N;j++){
                if(A[j]==i) a=j;
                if(A[j]==i+1) b=j;
            }
            if(b<a){
                int bb=b;
                while(A[bb]-A[b]==bb-b) bb++;
                
                vector<int> S;
                vector<vector<int>> T;
                if(b) S.push_back(b);
                S.push_back(bb-b);
                if(a-bb+1) S.push_back(a-bb+1);
                if(N-1-a) S.push_back(N-1-a);
                
                ans.push_back(S);
                
                int id=0;
                for(int a:S){
                    vector<int> U;
                    for(int x=id;x<id+a;x++){
                        U.push_back(A[x]);
                    }
                    T.push_back(U);
                    id+=a;
                }
                reverse(all(T));
                
                A.clear();
                for(int i=0;i<si(T);i++){
                    for(int x:T[i]) A.push_back(x);
                }
                
                break;
            }
        }
    }
    
    cout<<si(ans)<<"\n";
    for(int i=0;i<si(ans);i++){
        cout<<si(ans[i])<<" ";
        for(int a:ans[i]) cout<<a<<" ";
        cout<<"\n";
    }
}