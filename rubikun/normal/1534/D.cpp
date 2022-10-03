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
const int mod=1000000007,MAX=400005,INF=1<<30;

int main(){
    
    int N;cin>>N;
    set<pair<int,int>> SE;
    vector<int> S(N);
    cout<<"? "<<1<<endl;
    int cnt0=0,cnt1=0;
    for(int i=0;i<N;i++){
        cin>>S[i];
        if(S[i]==1){
            int a=0,b=i;
            SE.insert(mp(a,b));
        }
        if(S[i]&1) cnt1++;
        else cnt0++;
    }
    cnt0--;
    
    int t=-1;
    if(cnt0<=cnt1) t=0;
    else t=1;
    
    for(int i=1;i<N;i++){
        if((S[i]&1)==t){
            cout<<"? "<<i+1<<endl;
            for(int j=0;j<N;j++){
                int d;cin>>d;
                if(d==1){
                    int a=i,b=j;
                    if(a>b) swap(a,b);
                    SE.insert(mp(a,b));
                }
            }
        }
    }
    
    cout<<"!"<<endl;
    for(auto e:SE) cout<<e.fi+1<<" "<<e.se+1<<endl;
}