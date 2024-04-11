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
    
    int N;cin>>N;
    vector<int> pos(N);
    for(int i=0;i<N;i++){
        int x;cin>>x;x--;
        pos[x]=i;
    }
    int ma=0;
    int i=0;
    while(i<N){
        int j=i+1;
        while(j<N&&pos[j-1]<pos[j]) j++;
        chmax(ma,j-i);
        i=j;
    }
    cout<<N-ma<<endl;
}