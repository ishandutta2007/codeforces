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
const int mod=1000000009,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        vector<int> ans(N);
        bool f=true;
        int i=0;
        while(i<N){
            int j=i;
            while(j<N&&A[i]==A[j]) j++;
            if(j-i==1){
                f=false;
                break;
            }
            for(int k=i+1;k<j;k++) ans[k]=k-1;
            ans[i]=j-1;
            i=j;
        }
        if(f){
            for(int a:ans) cout<<a+1<<" ";
            cout<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
}