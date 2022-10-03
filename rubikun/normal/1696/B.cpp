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
        deque<int> A;
        for(int i=0;i<N;i++){
            int x;cin>>x;
            A.push_back(x);
        }
        while(si(A)&&A.front()==0) A.pop_front();
        while(si(A)&&A.back()==0) A.pop_back();
        if(si(A)==0){
            cout<<0<<"\n";
        }else{
            bool f=true;
            for(int x:A) f&=(x>0);
            if(f) cout<<1<<"\n";
            else cout<<2<<"\n";
        }
    }
}