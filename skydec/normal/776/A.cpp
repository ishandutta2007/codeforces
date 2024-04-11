#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
string A,B;
int main(){
    cin>>A>>B;
    cout<<A<<" "<<B<<endl;
    int n;cin>>n;
    while(n--){
        string C,D;
        cin>>C>>D;
        if(A==C)A=D;
        else if(B==C)B=D;
        cout<<A<<" "<<B<<endl;
    }
    return 0;
}