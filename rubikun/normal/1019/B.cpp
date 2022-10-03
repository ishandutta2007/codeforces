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
const int mod=1000000007,MAX=3005;
const ll INF=1LL<<60;

int ask(int id){
    cout<<"? "<<id+1<<endl;
    int res;cin>>res;
    return res;
}

void ans(int id){
    cout<<"! "<<id+1<<endl;
    exit(0);
}

int sign(int x,int y){
    if(y-x>0) return 1;
    if(y-x<0) return -1;
    return 0;
}

int main(){
    
    
    
    int N;cin>>N;
    if(N%4==2){
        cout<<"! "<<-1<<endl;
        return 0;
    }
    
    int x=ask(0),y=ask(N/2);
    if(sign(x,y)==0) ans(0);
    
    int left=0,right=N/2;
    while(right-left>1){
        int mid=(left+right)/2;
        int xx=ask(mid),yy=ask(mid+N/2);
        
        if(sign(xx,yy)==0) ans(mid);
        
        if(sign(x,y)==sign(xx,yy)) left=mid;
        else right=mid;
    }
}