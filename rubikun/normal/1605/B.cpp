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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        bool f=true;
        for(int i=0;i+1<N;i++) if(S[i]>S[i+1]) f=false;
        if(f){
            cout<<0<<"\n";
        }else{
            cout<<1<<"\n";
            int cnt=0;
            for(int i=0;i<N;i++) if(S[i]=='0') cnt++;
            vector<int> X;
            for(int i=0;i<cnt;i++) if(S[i]=='1') X.push_back(i);
            for(int i=cnt;i<N;i++) if(S[i]=='0') X.push_back(i);
            cout<<si(X);
            for(int a:X) cout<<" "<<a+1;
            cout<<"\n";
        }
    }
}