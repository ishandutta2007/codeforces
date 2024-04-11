#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1000000000000;

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second) return a.first>b.first;
    return a.second>b.second;
}

bool compare2(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<pair<int,int>> A(N);
        for(int i=0;i<N;i++){
            int a,f;cin>>a;
            f=1;
            a--;
            if(f==0){
                A[a].second++;
            }else{
                A[a].first++;
                A[a].second++;
            }
        }
        
        sort(all(A),compare);
        
        priority_queue<int> PQ;
        int sum=0,now=N+1;
        for(int i=0;i<N;i++){
            int a=A[i].second;
            if(a<now){
                sum+=a;
                now=a;
            }else{
                sum+=now-1;
                now--;
            }
            if(now==0) break;
        }
        
        cout<<sum<<endl;
        
        /*vector<int> B(N+1);
        
        sort(all(A),compare2);
        
        for(int i=0;i<N;i++){
            int a=A[i].first,b=A[i].second;
            while(B[b]&&b>=1){
                b--;
            }
            B[b]=min(a,b);
        }
        
        int sum2=0;
        
        for(int i=1;i<=N;i++){
            sum2+=B[i];
        }
        
        cout<<sum<<" "<<sum2<<endl;*/
    }
}