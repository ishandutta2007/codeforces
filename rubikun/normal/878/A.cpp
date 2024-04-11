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
const int mod=1000000007,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> type(N),X(N);
    for(int i=0;i<N;i++){
        char c;cin>>c;
        if(c=='^') type[i]=0;
        if(c=='|') type[i]=1;
        if(c=='&') type[i]=2;
        cin>>X[i];
    }
    
    vector<int> ans(3);
    
    int a=0,b=1023;
    for(int i=0;i<N;i++){
        if(type[i]==0){
            a^=X[i];
            b^=X[i];
        }
        if(type[i]==1){
            a|=X[i];
            b|=X[i];
        }
        if(type[i]==2){
            a&=X[i];
            b&=X[i];
        }
    }
    for(int k=0;k<10;k++){
        bool f=(a&(1<<k)),g=(b&(1<<k));
        if(f==0){
            if(g==0){
                
            }else{
                ans[2]|=(1<<k);
            }
        }else{
            if(g==0){
                ans[0]|=(1<<k);
                ans[2]|=(1<<k);
            }else{
                ans[1]|=(1<<k);
                ans[2]|=(1<<k);
            }
        }
    }
    
    cout<<3<<endl;
    cout<<"^ "<<ans[0]<<endl;
    cout<<"| "<<ans[1]<<endl;
    cout<<"& "<<ans[2]<<endl;
}