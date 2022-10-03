#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
double eps=1e-12;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    double R;cin>>R;
    vector<double> X(N),stop(N,R);
    for(int i=0;i<N;i++) cin>>X[i];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(abs(X[i]-X[j])>2*R+eps) continue;
            
            stop[i]=max(stop[i],stop[j]+sqrt(4.0*R*R-(X[i]-X[j])*(X[i]-X[j])));
        }
    }
    
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<setprecision(25)<<stop[i];
    }
    cout<<endl;
}