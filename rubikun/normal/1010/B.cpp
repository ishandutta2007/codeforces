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

int ask(int x){
    cout<<x<<endl;
    int res;cin>>res;
    return res;
}

int main(){
    
    
    
    int M,N;cin>>M>>N;
    int x=ask(1);
    if(x==0) return 0;
    
    vector<int> ans(N);
    ans[0]=x;
    
    for(int i=1;i<N;i++){
        ans[i]=ask(1);
    }
    
    int t=0;
    
    int left=1,right=M+1;
    while(right-left>1){
        int mid=(left+right)/2;
        int x=ask(mid);
        
        if(x==0) return 0;
        
        if(ans[t%N]==1){
            if(x==1) left=mid;
            else right=mid;
        }else{
            if(x==1) right=mid;
            else left=mid;
        }
        
        t++;
    }
}