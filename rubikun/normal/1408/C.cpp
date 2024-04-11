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

#define double long double

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,L;cin>>N>>L;
        vector<int> A(N+2),B(N+2);
        for(int i=0;i<N;i++) cin>>A[i+1];
        A[0]=0;
        A[N+1]=L;
        
        for(int i=0;i<N+2;i++) B[i]=L-A[i];
        reverse(all(B));
        
        double left=0,right=L;
        for(int k=0;k<100;k++){
            double mid=(left+right)/2.0;
            
            double a=0,b=0;
            
            for(int i=0;i<N+1;i++){
                if(A[i+1]<=mid){
                    a+=(A[i+1]-A[i])/(double)(i+1);
                }else{
                    a+=(mid-A[i])/(double)(i+1);
                    break;
                }
            }
            
            mid=L-mid;
            
            for(int i=0;i<N+1;i++){
                if(B[i+1]<=mid){
                    b+=(B[i+1]-B[i])/(double)(i+1);
                }else{
                    b+=(mid-B[i])/(double)(i+1);
                    break;
                }
            }
            
            mid=L-mid;
            
            if(a<b) left=mid;
            else right=mid;
        }
        
        double ans=0;
        
        for(int i=0;i<N+1;i++){
            if(A[i+1]<=left){
                ans+=(A[i+1]-A[i])/(double)(i+1);
            }else{
                ans+=(left-A[i])/(double)(i+1);
                break;
            }
        }
        
        cout<<setprecision(25)<<ans<<"\n";
    }
}