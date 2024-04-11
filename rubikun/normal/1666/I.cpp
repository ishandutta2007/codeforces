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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<60;

int ask(int h,int w){
    cout<<"SCAN "<<h+1<<" "<<w+1<<endl;
    int x;cin>>x;
    return x;
}

bool check(int h,int w){
    cout<<"DIG "<<h+1<<" "<<w+1<<endl;
    int x;cin>>x;
    return x;
}
int main(){
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        int x=ask(0,0),y=ask(0,W-1);
        int hsum=(x+y-2*(W-1))/2,wsum=(x-y+2*(W-1))/2;
        int hh=ask(hsum/2,0),ww=ask(0,wsum/2);
        int c=(hh+hsum-wsum)/2,a=hsum-c;
        int d=(ww-hsum+wsum)/2,b=wsum-d;
        if(check(a,b)){
            check(c,d);
            continue;
        }else{
            check(a,d);
            check(c,b);
        }
    }
}