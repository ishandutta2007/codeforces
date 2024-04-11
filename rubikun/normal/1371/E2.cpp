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
    
    int N,P;cin>>N>>P;
    map<int,int> MA;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    sort(all(A));
    
    int left=max(1,A.back()-(N-1)),right=A.back();
    
    int i=0;
    while(i<N){
        if(A[i]<left) i++;
        else break;
    }
    MA[left-1]=i;
    while(i<N){
        MA[A[i]]++;
        i++;
    }
    for(int i=left;i<=right;i++){
        MA[i]+=MA[i-1];
        //cout<<i<<" "<<MA[i]<<endl;
    }
    
    set<int> ng;
    
    for(int i=left;i<=right;i++){
        int s=i/P*P+(P+i-MA[i]%P)%P;
        while(s+P<=i) s+=P;
        while(s>i) s-=P;
        while(1){
            if(ng.count(s)) break;
            ng.insert(s);
            s-=P;
            if(s<left) break;
        }
    }
    //for(int x:ng) cout<<x<<" ";
    //cout<<endl;
    
    vector<int> ans;
    
    for(int i=left;i<=right;i++){
        if(ng.count(i)==0){
            int a=N-(right-i);
            if(a<P) ans.push_back(i);
        }
    }
    
    cout<<si(ans)<<"\n";
    for(int a:ans) cout<<a<<" ";
    cout<<"\n";
}