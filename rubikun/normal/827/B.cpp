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
    
    int N,K;cin>>N>>K;
    N--;
    int d=N/K;
    int a=N%K;
    int b=K-a;
    
    if(a>=2) cout<<2*d+2<<endl;
    else if(a==1) cout<<2*d+1<<endl;
    else cout<<2*d<<endl;
    
    int now=2;
    for(int i=0;i<a;i++){
        cout<<1<<" "<<now<<"\n";
        now++;
        for(int j=0;j<d;j++){
            cout<<now-1<<" "<<now<<"\n";
            now++;
        }
    }
    
    for(int i=0;i<b;i++){
        cout<<1<<" "<<now<<"\n";
        now++;
        for(int j=0;j<d-1;j++){
            cout<<now-1<<" "<<now<<"\n";
            now++;
        }
    }
}