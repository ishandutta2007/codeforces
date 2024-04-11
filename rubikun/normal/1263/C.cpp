#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=3005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T){
        int N;cin>>N;
        set<int> SE;
        SE.insert(0);
        for(int i=1;i*i<=N;i++){
            SE.insert(N/i);
        }
        
        for(int i=1;i<=40000;i++){
            int x=N/(i+1);
            SE.insert(N/(x+1));
        }
        
        cout<<SE.size()<<"\n";
        for(auto it=SE.begin();it!=SE.end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
        
        T--;
    }
}