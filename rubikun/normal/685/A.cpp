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
const int mod=1000000007,MAX=205,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> X={1};
    while(si(X)<=7) X.push_back(X.back()*7);
    X.push_back(INF);
    
    int cnt1=0,cnt2=0;
    for(int i=1;i<si(X);i++){
        if(N<=X[i]){
            cnt1=i;
            break;
        }
    }
    for(int i=1;i<si(X);i++){
        if(M<=X[i]){
            cnt2=i;
            break;
        }
    }
    
    if(cnt1+cnt2>=8){
        cout<<0<<endl;
        return 0;
    }
    
    vector<int> id(7);
    iota(all(id),0);
    
    set<pair<int,int>> SE;
    
    //cout<<cnt1<<" "<<cnt2<<endl;
    
    do{
        int a=0,b=0;
        for(int i=0;i<cnt1;i++){
            a*=7;
            a+=id[i];
        }
        for(int i=0;i<cnt2;i++){
            b*=7;
            b+=id[cnt1+i];
        }
        
        if(a<N&&b<M) SE.insert(mp(a,b));
        
    }while(next_permutation(all(id)));
    
    cout<<si(SE)<<endl;
}