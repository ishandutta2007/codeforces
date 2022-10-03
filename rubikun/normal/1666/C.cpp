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
    
    vector<ll> X(3),Y(3);
    vector<ll> A,B;
    for(int i=0;i<3;i++){
        cin>>X[i]>>Y[i];
    }
    A=X;B=Y;
    sort(all(A));
    sort(all(B));
    vector<vector<ll>> ans;
    ll ox=A[1],oy=B[1];
    for(int i=0;i<3;i++){
        if(ox==X[i]){
            if(oy==Y[i]){
                
            }else{
                ans.push_back({ox,oy,ox,Y[i]});
            }
        }else{
            if(oy==Y[i]){
                ans.push_back({ox,oy,X[i],oy});
            }else{
                ans.push_back({ox,oy,ox,Y[i]});
                ans.push_back({ox,Y[i],X[i],Y[i]});
            }
        }
    }
    cout<<si(ans)<<endl;
    for(auto a:ans){
        for(int b:a) cout<<b<<" ";
        cout<<"\n";
    }
}