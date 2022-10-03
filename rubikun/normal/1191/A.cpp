#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int x;cin>>x;
    if(x%4==0){
        cout<<"1 A"<<endl;
    }else if(x%4==1){
        cout<<"0 A"<<endl;
    }else if(x%4==2){
        cout<<"1 B"<<endl;
    }else if(x%4==3){
        cout<<"2 A"<<endl;
    }
}