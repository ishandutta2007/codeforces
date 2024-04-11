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

void update(pair<int,int> &a,int b){
    chmin(a.fi,b);
    chmax(a.se,b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    pair<int,int> lx,ly,rx,ry;
    lx=ly=rx=ry=mp(INF,-INF);
    
    for(int t=0;t<4;t++){
        int x,y;cin>>x>>y;
        update(lx,x);
        update(ly,y);
    }
    
    for(int t=0;t<4;t++){
        int x,y;cin>>x>>y;
        update(rx,x);
        update(ry,y);
    }
    
    //cout<<lx.fi<<" "<<lx.se<<endl;
    //cout<<ly.fi<<" "<<ly.se<<endl;
    //cout<<rx.fi<<" "<<rx.se<<endl;
    //cout<<ry.fi<<" "<<ry.se<<endl;
    
    bool ok=false;
    
    for(int x=lx.fi;x<=lx.se;x++){
        for(int y=ly.fi;y<=ly.se;y++){
            if(x<rx.fi||x>rx.se) continue;
            if(y<ry.fi||y>ry.se) continue;
            int s=abs((rx.fi+rx.se)/2-x);
            int t=abs((ry.fi+ry.se)/2-y);
            
            if(s+t<=(rx.se-rx.fi)/2) ok=true;
        }
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}