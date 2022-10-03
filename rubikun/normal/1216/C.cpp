#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    vector<double> x(6),y(6);
    for(int i=0;i<6;i++){
        cin>>x[i]>>y[i];
    }
    
    bool ok=true;
    
    for(double i=x[0]+0.5;i<x[1];i+=1.0){
        bool c=false;
        if(x[2]<i&&i<x[3]&&y[2]<y[0]+0.5&&y[0]+0.5<y[3]) c=true;
        if(x[4]<i&&i<x[5]&&y[4]<y[0]+0.5&&y[0]+0.5<y[5]) c=true;
        if(!c) ok=false;
        
        c=false;
        if(x[2]<i&&i<x[3]&&y[2]<y[1]-0.5&&y[1]-0.5<y[3]) c=true;
        if(x[4]<i&&i<x[5]&&y[4]<y[1]-0.5&&y[1]-0.5<y[5]) c=true;
        if(!c) ok=false;
    }
    
    for(double i=y[0]+0.5;i<y[1];i+=1.0){
        bool c=false;
        if(y[2]<i&&i<y[3]&&x[2]<x[0]+0.5&&x[0]+0.5<x[3]) c=true;
        if(y[4]<i&&i<y[5]&&x[4]<x[0]+0.5&&x[0]+0.5<x[5]) c=true;
        if(!c) ok=false;
        
        c=false;
        if(y[2]<i&&i<y[3]&&x[2]<x[1]-0.5&&x[1]-0.5<x[3]) c=true;
        if(y[4]<i&&i<y[5]&&x[4]<x[1]-0.5&&x[1]-0.5<x[5]) c=true;
        if(!c) ok=false;
    }
    
    if(!ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}