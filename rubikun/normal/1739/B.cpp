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
        vector<int> D(N);
        for(int i=0;i<N;i++) cin>>D[i];
        int sum=D[0];
        bool ok=true;
        for(int i=1;i<N;i++){
            if(D[i]){
                if(sum>=D[i]) ok=false;
            }
            sum+=D[i];
        }
        if(ok){
            int s=0;
            for(int i=0;i<N;i++){
                s+=D[i];
                cout<<s<<" ";
            }
            cout<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}