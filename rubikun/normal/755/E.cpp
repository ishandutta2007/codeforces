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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    if(N<=3){
        cout<<-1<<endl;
        return 0;
    }
    if(N==4){
        if(K==3){
            cout<<3<<endl;
            cout<<1<<" "<<2<<endl;
            cout<<2<<" "<<3<<endl;
            cout<<3<<" "<<4<<endl;
        }else{
            cout<<-1<<endl;
        }
        return 0;
    }
    if(K==1){
        cout<<-1<<endl;
        return 0;
    }
    if(K==2){
        cout<<N-1<<"\n";
        for(int i=1;i<N;i++){
            cout<<i<<" "<<i+1<<"\n";
        }
        return 0;
    }
    if(K==3){
        cout<<2+(N-2)*(N-3)/2<<"\n";
        cout<<1<<" "<<2<<"\n";
        cout<<N-1<<" "<<N<<"\n";
        for(int i=2;i<=N-1;i++){
            for(int j=i+1;j<=N-1;j++){
                cout<<i<<" "<<j<<"\n";
            }
        }
        return 0;
    }
    cout<<-1<<"\n";
}