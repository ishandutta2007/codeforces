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

bool ask(int sh,int sw,int gh,int gw,bool f){
    if(f) cout<<"? "<<sh+1<<" "<<sw+1<<" "<<gh+1<<" "<<gw+1<<endl;
    else cout<<"? "<<gh+1<<" "<<gw+1<<" "<<sh+1<<" "<<sw+1<<endl;
    string res;cin>>res;
    if(res=="YES") return true;
    else return false;
}

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    int N;cin>>N;
    int nowh=0,noww=0;
    
    int cntr=0;
    
    string ans,ans2;
    
    vector<pair<int,int>> pos={mp(0,0)};
    
    for(int t=0;t<N-1;t++){
        if(noww+1<N){
            bool x=ask(nowh,noww+1,N-1,N-1,1);
            if(x){
                ans+='R';
                noww++;
                pos.push_back(mp(nowh,noww));
                cntr++;
                continue;
            }
        }
        
        ask(nowh+1,noww,N-1,N-1,1);
        ans+='D';
        nowh++;
        pos.push_back(mp(nowh,noww));
    }
    
    int mh=nowh,mw=noww;
    
    pos.pop_back();
    
    reverse(all(pos));
    
    nowh=N-1;noww=N-1;
    
    for(int t=0;t<N-2;t++){
        if(nowh-1>=0){
            bool x=ask(nowh-1,noww,0,0,0);
            if(x){
                ans2+='D';
                nowh--;
                continue;
            }
        }
        
        //ask(nowh-1,noww,pos[t].fi,pos[t].se,0);
        ans2+='R';
        noww--;
        cntr++;
    }
    
    if(cntr==N-1) ans2+='D';
    else ans2+='R';
    
    reverse(all(ans2));
    
    ans+=ans2;
    
    cout<<"! "<<ans<<endl;
}