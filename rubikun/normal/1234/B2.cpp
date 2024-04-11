#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    map<int,int> MA;
    deque<int> DQ;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(MA[a]) continue;
        if(DQ.size()==K){
            MA[DQ.front()]=0;
            DQ.pop_front();
        }
        MA[a]=1;
        DQ.push_back(a);
    }
    
    cout<<DQ.size()<<endl;
    for(int i=DQ.size()-1;i>=0;i--){
        cout<<DQ[i]<<" ";
    }
    cout<<endl;
}