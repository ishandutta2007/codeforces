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
    vector<int> A;
    for(int i=0;i<N;i++){
        A.push_back(1);
        while(si(A)>=2&&A[si(A)-2]==A[si(A)-1]){
            int a=A.back();
            A.pop_back();A.pop_back();
            A.push_back(a+1);
        }
    }
    for(int a:A) cout<<a<<" ";
    cout<<endl;
}