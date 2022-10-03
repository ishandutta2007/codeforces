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
//const ll INF=1LL<<60;

int ask(int id){
    cout<<"? "<<id<<endl;
    int res;cin>>res;
    return res;
}

int main(){
    
    
    
    int N;cin>>N;
    vector<int> p(N+2);
    p[0]=INF;
    p[N+1]=INF;
    
    if(N==1){
        cout<<"! 1"<<endl;
        return 0;
    }
    
    p[1]=ask(1);
    p[2]=ask(2);
    
    if(p[1]<p[2]){
        cout<<"! 1"<<endl;
        return 0;
    }
    
    p[N-1]=ask(N-1);
    p[N]=ask(N);
    
    if(p[N-1]>p[N]){
        cout<<"! "<<N<<endl;
        return 0;
    }
    
    int left=1,right=N-1;
    
    while(right-left>1){
        int mid=(left+right)/2;
        p[mid]=ask(mid);
        p[mid+1]=ask(mid+1);
        
        if(p[mid]<p[mid+1]) right=mid;
        else left=mid;
    }
    
    cout<<"! "<<right<<endl;
    
    return 0;
    
    
}