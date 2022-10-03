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
    
    int N;cin>>N;
    map<int,int> MA;
    vector<int> A(N);
    
    for(int i=0;i<N;i++){
        cin>>A[i];
        MA[A[i]]++;
    }
    
    sort(all(A));
    
    int left=0,right=N-MA[A[0]]+1;
    
    while(right-left>1){
        int mid=(left+right)/2;
        bool ok=true;
        for(int i=0;i<mid;i++){
            if(A[i]>=A[N-mid+i]) ok=false;
        }
        if(ok) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}