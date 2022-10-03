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
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        map<int,int> MA;
        for(int i=0;i<N;i++){
            cin>>A[i];
            MA[A[i]]++;
        }
        bool ok=true;
        for(int i=0;i<N;i++){
            if(MA[A[i]]&1) ok=false;
        }
        if(!ok){
            cout<<-1<<"\n";
            continue;
        }
        vector<pair<int,int>> que;
        int ad=0;
        vector<int> L,R;
        for(int s=0;s<N;s+=2){
            if(A[s]==A[s+1]){
                L.push_back(2);
                continue;
            }
            for(int t=s+1;t<N;t++){
                if(A[s]==A[t]){
                    for(int i=N-1;i>=t;i--) que.push_back(mp(t+(N-1-i),A[i]));
                    reverse(A.begin()+t,A.end());
                    R.push_back(N-t+N-t);
                    for(int i=N-1;i>=s+1;i--) que.push_back(mp(s+1+(N-1-i),A[i]));
                    reverse(A.begin()+s+1,A.end());
                    R.push_back(N-1-s+N-1-s);
                    L.push_back(2);
                    break;
                }
            }
        }
        cout<<si(que)<<"\n";
        for(auto a:que) cout<<a.fi<<" "<<a.se<<"\n";
        cout<<si(L)+si(R)<<"\n";
        for(int a:L) cout<<a<<" ";
        reverse(all(R));
        for(int a:R) cout<<a<<" ";
        cout<<"\n";
        
    }
}