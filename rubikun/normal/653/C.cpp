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
const int mod=998244353,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    set<int> ng;
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i+1<N;i++){
        if(i%2==0){
            if(A[i]>=A[i+1]){
                ng.insert(i);
                ng.insert(i+1);
            }
        }else{
            if(A[i]<=A[i+1]){
                ng.insert(i);
                ng.insert(i+1);
            }
        }
    }
    
    if(si(ng)>=10){
        cout<<0<<endl;
        return 0;
    }
    
    set<pair<int,int>> SE;
    
    auto check=[&](int a,int b){
        swap(A[a],A[b]);
        bool ok=true;
        for(int i=a-3;i<=a+3;i++){
            if(i<0||i+1>=N) continue;
            if(i%2==0){
                if(A[i]>=A[i+1]) ok=false;
            }else{
                if(A[i]<=A[i+1]) ok=false;
            }
        }
        for(int i=b-3;i<=b+3;i++){
            if(i<0||i+1>=N) continue;
            if(i%2==0){
                if(A[i]>=A[i+1]) ok=false;
            }else{
                if(A[i]<=A[i+1]) ok=false;
            }
        }
        for(int a:ng){
            for(int i=a-1;i<=a+1;i++){
                if(i<0||i+1>=N) continue;
                if(i%2==0){
                    if(A[i]>=A[i+1]) ok=false;
                }else{
                    if(A[i]<=A[i+1]) ok=false;
                }
            }
        }
        if(ok){
            SE.insert(mp(min(a,b),max(a,b)));
        }
        swap(A[a],A[b]);
        return;
    };
    
    for(int x:ng){
        for(int i=0;i<N;i++){
            check(i,x);
        }
    }
    
    cout<<si(SE)<<endl;
}