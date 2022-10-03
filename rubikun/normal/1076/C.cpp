#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        double D;cin>>D;
        if(D==0.0) cout<<"Y 0.000000000 0.000000000"<<endl;
        else if(D<=3.0) cout<<"N"<<endl;
        else{
            cout<<"Y ";
            cout<<setprecision(25)<<((D+sqrt(D*D-D*4.0))/2.0)<<" "<<((D-sqrt(D*D-D*4.0))/2.0)<<endl;
        }
    }
}