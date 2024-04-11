#include <iostream>
using namespace std;
int n;
int a[5]={100,20,10,5,1};
int main(){
    cin>>n;
    int ans=0;
    for(int i=0;i<5;i++){
        ans+=n/a[i];
        n%=a[i];
    }
    cout<<ans<<endl;
}