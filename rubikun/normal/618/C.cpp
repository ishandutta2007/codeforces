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

ll area(vector<ll> a,vector<ll> b,vector<ll> c){
    b[0]-=a[0];
    b[1]-=a[1];
    c[0]-=a[0];
    c[1]-=a[1];
    return abs(b[0]*c[1]-b[1]*c[0]);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<ll>> S(N);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        S[i]={a,b,i+1};
    }
    sort(all(S));
    for(int i=0;i+2<N;i++){
        if(area(S[i],S[i+1],S[i+2])){
            cout<<S[i][2]<<" "<<S[i+1][2]<<" "<<S[i+2][2]<<endl;
            return 0;
        }
    }
    //cout<<S[0][2]<<" "<<S[1][2]<<" "<<S[2][2]<<endl;
}