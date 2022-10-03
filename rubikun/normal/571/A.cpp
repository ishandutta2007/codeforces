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
const int mod=1000000007,MAX=20;
const int INF=1<<30;
//const ll INF=1LL<<60;

ll f(ll A,ll B,ll y){
    if(y<0) return 0;
    if(y<=A){
        return (1+y+1)*(y+1)/2;
    }else if(y<=B){
        return (1+A+1)*(A+1)/2+(y-A)*(A+1);
    }else if(y<=A+B){
        return (1+A+1)*(A+1)/2+(B-A)*(A+1)+((A)+(A+B-y+1))*(y-B)/2;
    }else{
        return (1+A+1)*(A+1)/2+(B-A)*(A+1)+((A)+(1))*(A)/2;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b,c,l;cin>>a>>b>>c>>l;
    ll ans=0;
    
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    
    swap(a,c);
    
    int sum=a+b+c;
    
    for(int x=0;x<=l;x++){
        int A=(sum+x-1)/2-a,B=(sum+x-1)/2-b,C=(sum+x-1)/2-c;
        if(A<0||B<0||C<0) continue;
        if(A+B+C<x) continue;
        
        ans+=f(A,B,x);
        ans-=f(A,B,x-C-1);
        
        //cout<<x<<" "<<ans<<endl;
    }
    
    cout<<ans<<endl;
}