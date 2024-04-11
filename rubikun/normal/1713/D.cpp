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
const int mod=998244353,MAX=200005,INF=1<<30;

int ask(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    int res;cin>>res;
    return res;
}

void output(int a){
    cout<<"! "<<a<<endl;
    return;
}

void solve(){
    int N;cin>>N;
    N=(1<<N);
    vector<int> alive(N);iota(all(alive),1);
    while(1){
        vector<int> nex;
        if(si(alive)==2){
            int res=ask(alive[0],alive[1]);
            if(res==1){
                output(alive[0]);
                return;
            }
            if(res==2){
                output(alive[1]);
                return;
            }
        }
        if(si(alive)==1){
            output(alive[0]);
            return;
        }
        
        for(int i=0;i<si(alive);i+=4){
            int a=alive[i],b=alive[i+1],c=alive[i+2],d=alive[i+3];
            int x=ask(a,c);
            if(x==1){
                int y=ask(a,d);
                if(y==1) nex.push_back(a);
                else nex.push_back(d);
            }else if(x==2){
                int y=ask(b,c);
                if(y==1) nex.push_back(b);
                else nex.push_back(c);
            }else{
                int y=ask(b,d);
                if(y==1) nex.push_back(b);
                else nex.push_back(d);
            }
        }
        
        alive=nex;
    }
}

int main(){
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}