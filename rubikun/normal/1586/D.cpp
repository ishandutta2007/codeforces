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
    
    int N;cin>>N;
    int cnt=0;
    for(int i=1;i<=N;i++){
        cout<<"?";
        for(int j=0;j<N-1;j++) cout<<" "<<i;
        cout<<" "<<1<<endl;
        
        int x;cin>>x;
        if(x>0) cnt++;
    }
    
    vector<int> ans(N);
    ans.back()=cnt+1;
    
    for(int i=1;i<=N;i++){
        cout<<"?";
        for(int j=0;j<N-1;j++) cout<<" "<<i;
        cout<<" "<<N+1-ans.back()<<endl;
        int x;cin>>x;
        if(x>0) ans[x-1]=N+1-i;
    }
    
    cout<<"!";
    
    for(int i=0;i<N;i++) cout<<" "<<ans[i];
    cout<<endl;
}