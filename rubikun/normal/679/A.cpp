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
    vector<int> t={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
    int cnt=0;
    
    for(int a:t){
        cout<<a<<endl;
        string S;cin>>S;
        if(S=="yes") cnt++;
    }
    
    if(cnt<=1) cout<<"prime"<<endl;
    else cout<<"composite"<<endl;
    
    
}