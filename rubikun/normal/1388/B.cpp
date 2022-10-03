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
    
    int Q;cin>>Q;
    
    while(Q--){
        int N;cin>>N;
        if(N==1) cout<<8<<"\n";
        else if(N==2) cout<<98<<"\n";
        else if(N==3) cout<<998<<"\n";
        else{
            int a=(N+3)/4;
            for(int i=0;i<N-a;i++) cout<<9;
            for(int i=0;i<a;i++) cout<<8;
            cout<<"\n";
        }
    }
}