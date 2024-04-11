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
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),nex(N);
    int p=0,q=0,ans=0;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    nex[N-1]=-1;
    for(int i=N-2;i>=0;i--){
        if(A[i]==A[i+1]) nex[i]=nex[i+1];
        else nex[i]=A[i+1];
    }
    
    for(int i=0;i<N;i++){
        if(nex[i]==-1){
            if(p!=A[i]){
                p=A[i];
                ans++;
            }else if(q!=A[i]){
                q=A[i];
                ans++;
            }
        }else{
            if(p!=A[i]&&q!=A[i]){
                if(p==nex[i]){
                    p=A[i];
                    ans++;
                }else{
                    q=A[i];
                    ans++;
                }
            }else if(p!=A[i]){
                p=A[i];
                ans++;
            }else if(q!=A[i]){
                q=A[i];
                ans++;
            }
        }
    }
    
    cout<<ans<<endl;
}