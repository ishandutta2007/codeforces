#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
const long double eps=1e-8;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    stack<pair<long double,int>> ST;
    
    for(int i=0;i<N;i++){
        if(ST.empty()){
            ST.push({A[i],1});
        }else{
            if(ST.top().first<A[i]){
                ST.push({A[i],1});
            }else{
                double a=ST.top().first;
                int b=ST.top().second;
                ST.pop();
                
                ST.push({(a*b+A[i])/double(b+1),b+1});
            }
            
            while(ST.size()>=2){
                pair<double,int> a=ST.top();
                ST.pop();
                pair<double,int> b=ST.top();
                ST.pop();
                
                if(a.first>b.first){
                    ST.push(b);
                    ST.push(a);
                    break;
                }else{
                    ST.push({(a.first*a.second+b.first*b.second)/double(a.second+b.second),a.second+b.second});
                }
            }
        }
    }
    
    vector<double> ans(N);
    int now=0;
    
    while(!ST.empty()){
        double a=ST.top().first;
        int b=ST.top().second;
        ST.pop();
        for(int i=now;i<now+b;i++) ans[i]=a;
        now+=b;
    }
    
    reverse(all(ans));
    
    for(int i=0;i<N;i++){
        cout<<setprecision(25)<<ans[i]<<"\n";
    }
}