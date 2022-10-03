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
const int mod=998244353,MAX=400005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,x,y;cin>>N>>x>>y;
        if(x>y) swap(x,y);
        if(x){
            cout<<"-1\n";
        }else if(y==0){
            cout<<"-1\n";
        }else{
            if((N-1)%y==0){
                for(int i=1;i<=N-1;i++){
                    cout<<(i-1)/y*y+2<<" ";
                }
                cout<<"\n";
            }else{
                cout<<-1<<"\n";
            }
        }
    }
}