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
    
    int N;cin>>N;
    vector<int> ans(N,INF);
    for(int t=0;t<10;t++){
        vector<int> S,T;
        for(int i=0;i<N;i++){
            if(i&(1<<t)) T.push_back(i);
            else S.push_back(i);
        }
        if(si(S)){
            cout<<si(S)<<endl;
            for(int a:S) cout<<a+1<<" ";
            cout<<endl;
            vector<int> res(N);
            for(int j=0;j<N;j++){
                cin>>res[j];
            }
            for(int a:T){
                chmin(ans[a],res[a]);
            }
        }
        if(si(T)){
            cout<<si(T)<<endl;
            for(int a:T) cout<<a+1<<" ";
            cout<<endl;
            vector<int> res(N);
            for(int j=0;j<N;j++){
                cin>>res[j];
            }
            for(int a:S){
                chmin(ans[a],res[a]);
            }
        }
    }
    
    cout<<-1<<endl;
    for(int a:ans) cout<<a<<" ";
    cout<<endl;
}