#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;
 
bool compare(string a,string b){
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
 
int main(){
    
    vector<string> A(3);
    for(int i=0;i<3;i++){
        cin>>A[i];
    }
    sort(all(A),compare);
    if(A[0][1]==A[1][1]&&A[1][1]==A[2][1]){
        if(A[0][0]==A[1][0]&&A[1][0]==A[2][0]) cout<<0<<endl;
        else if(A[1][0]-A[0][0]==1&&A[2][0]-A[1][0]==1) cout<<0<<endl;
        else if(A[0][0]==A[1][0]||A[1][0]==A[2][0]) cout<<1<<endl;
        else if(A[1][0]-A[0][0]<=2||A[2][0]-A[1][0]<=2) cout<<1<<endl;
        else cout<<2<<endl;
    }else if(A[0][1]==A[1][1]){
        if(A[0][0]==A[1][0]) cout<<1<<endl;
        else if(A[1][0]-A[0][0]<=2) cout<<1<<endl;
        else cout<<2<<endl;
    }else if(A[1][1]==A[2][1]){
        if(A[1][0]==A[2][0]) cout<<1<<endl;
        else if(A[2][0]-A[1][0]<=2) cout<<1<<endl;
        else cout<<2<<endl;
    }else cout<<2<<endl;
}