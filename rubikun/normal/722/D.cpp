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
    priority_queue<int> PQ;
    set<int> SE;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        PQ.push(a);
        SE.insert(a);
    }
    
    while(1){
        int a=PQ.top();
        PQ.pop();
        SE.erase(a);
        
        int now=a;
        while(1){
            int to=now/2;
            if(to<=0) break;
            if(SE.count(to)==0){
                SE.insert(to);
                PQ.push(to);
                break;
            }
            now=to;
        }
        
        if(si(SE)!=N){
            SE.insert(a);
            break;
        }
    }
    
    for(int a:SE) cout<<a<<" ";
    cout<<endl;
}