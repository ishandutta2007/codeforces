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
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

const int D=1000;

struct dat{
    int x;
    int y;
    int id;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<dat> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i].x>>P[i].y;
        P[i].id=i;
    }
    sort(all(P),[](auto a,auto b){
        if(a.x/D!=b.x/D){
            return a.x/D<b.x/D;
        }else{
            if((a.x/D)&1){
                return a.y>b.y;
            }else{
                return a.y<b.y;
            }
        }
    });
    
    for(int i=0;i<N;i++) cout<<P[i].id+1<<" ";
    cout<<"\n";
}