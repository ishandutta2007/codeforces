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
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S,T;cin>>S>>T;
    sort(all(S));
    sort(all(T));
    
    int N=si(S);
    
    int ida0=0,ida1=(N-1)/2,idb0=N-1-(N-2)/2,idb1=N-1,idc0=0,idc1=N-1;
    
    vector<char> ans(N);
    
    int which=1;
    while(idc0<=idc1){
        if(which){
            if(S[ida0]<T[idb1]){
                ans[idc0]=S[ida0];
                ida0++;
                idc0++;
            }else{
                ans[idc1]=S[ida1];
                ida1--;
                idc1--;
            }
            which^=1;
        }else{
            if(S[ida0]<T[idb1]){
                ans[idc0]=T[idb1];
                idb1--;
                idc0++;
            }else{
                ans[idc1]=T[idb0];
                idb0++;
                idc1--;
            }
            which^=1;
        }
    }
    
    for(int i=0;i<N;i++) cout<<ans[i];
    cout<<endl;
}