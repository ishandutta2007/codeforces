#include <iostream>
using namespace std;
int t; // 
int n; // DLS
int p; // y = x + p[i]
int m;
int q;
long long ans[1000],D[2],J[2];
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        for(int j=0;j<2;j++){D[j]=0; J[j]=0;}
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>p;
            D[p%2]++;
        }
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>q;
            J[q%2]++;
        }
        ans[i]=D[0]*J[0]+D[1]*J[1];
    }
    for(int i=0;i<t;i++)cout<<ans[i]<<endl;
    return 0;
}