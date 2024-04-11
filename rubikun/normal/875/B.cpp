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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> on(N);
    cout<<1;
    int r=N;
    for(int i=0;i<N;i++){
        int p;cin>>p;p--;
        on[p]=1;
        while(r-1>=0){
            if(on[r-1]) r--;
            else break;
        }
        cout<<" "<<(i+1)-(N-r)+1;
    }
    cout<<endl;
}