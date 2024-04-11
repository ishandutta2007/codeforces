#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=500003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    vector<int> A(4),ans(6);
    cout<<"? 1 2"<<endl;
    cin>>A[0];
    cout<<"? 3 4"<<endl;
    cin>>A[1];
    cout<<"? 1 3"<<endl;
    cin>>A[2];
    cout<<"? 1 5"<<endl;
    cin>>A[3];
    vector<int> B={4,8,15,16,23,42};
    do{
        bool ok=true;
        if(B[0]*B[1]!=A[0]) ok=false;
        if(B[2]*B[3]!=A[1]) ok=false;
        if(B[0]*B[2]!=A[2]) ok=false;
        if(B[0]*B[4]!=A[3]) ok=false;
        if(ok) for(int i=0;i<6;i++) ans[i]=B[i];
    }while(next_permutation(all(B)));
    
    cout<<"!";
    for(int i=0;i<6;i++) cout<<" "<<ans[i];
    cout<<endl;
}