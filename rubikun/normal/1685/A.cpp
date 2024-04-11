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
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        
        if(N&1){
            cout<<"NO\n";
        }else{
            map<int,int> cn;
            for(int a:A) cn[a]++;
            pair<int,int> ma=mp(-1,-1);
            for(auto a:cn) chmax(ma,mp(a.se,a.fi));
            if(ma.fi>N/2){
                cout<<"NO\n";
            }else if(ma.fi==N/2){
                vector<int> ans;
                for(int i=0;i<N;i++){
                    if(A[i]==ma.se) continue;
                    ans.push_back(A[i]);
                    ans.push_back(ma.se);
                }
                bool f=true;
                for(int i=0;i<N;i++){
                    int a=ans[(i+N-1)%N],b=ans[i],c=ans[(i+1)%N];
                    if((a<b&&b>c)||(a>b&&b<c)){
                        
                    }else{
                        f=false;
                    }
                }
                if(f){
                    cout<<"YES\n";
                    for(int a:ans) cout<<a<<" ";
                    cout<<"\n";
                }else{
                    cout<<"NO\n";
                }
            }else{
                vector<int> ans(N);
                for(int i=0;i<N;i++){
                    if(i<N/2) ans[i*2]=A[i];
                    else ans[(i-N/2)*2+1]=A[i];
                }
                cout<<"YES\n";
                for(int a:ans) cout<<a<<" ";
                cout<<"\n";
            }
        }
    }
}