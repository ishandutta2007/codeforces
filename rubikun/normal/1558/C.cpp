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
const int mod=998244353,MAX=4000005;
const ll INF=1LL<<62;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),ans;
        bool ok=true;
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]--;
            if(abs(A[i]-i)&1) ok=false;
        }
        if(!ok){
            cout<<-1<<"\n";
            continue;
        }
        
        for(int t=N-1;t>=2;t-=2){
            int a=-1,b=-1;
            for(int i=0;i<N;i++){
                if(A[i]==t) a=i;
            }
            ans.push_back(a);
            reverse(A.begin(),A.begin()+a+1);
            
            for(int i=0;i<N;i++){
                if(A[i]==t-1) b=i;
            }
            ans.push_back(b-1);
            reverse(A.begin(),A.begin()+b);
            
            ans.push_back(b+1);
            reverse(A.begin(),A.begin()+b+2);
            
            ans.push_back(2);
            reverse(A.begin(),A.begin()+3);
            
            ans.push_back(t);
            reverse(A.begin(),A.begin()+t+1);
            
            //for(int a:A) cout<<a<<" ";
            //cout<<endl;
        }
        
        cout<<si(ans)<<"\n";
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }
}