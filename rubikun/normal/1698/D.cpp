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
const int mod=998244353,MAX=300005,INF=1<<30;

vector<int> ask(int l,int r){
    cout<<"? "<<l+1<<" "<<r<<endl;
    vector<int> res(r-l);
    for(int i=0;i<r-l;i++){
        cin>>res[i];res[i]--;
    }
    return res;
}

int main(){
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            auto res=ask(left,mid);
            int good=0;
            for(int a:res){
                if(left<=a&&a<mid) good++;
            }
            if(good&1) right=mid;
            else left=mid;
        }
        cout<<"! "<<left+1<<endl;
    }
    
}