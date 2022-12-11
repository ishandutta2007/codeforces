#include <iostream>
#include <algorithm>
using namespace std;
int t,n,l,r;
int main(){
    cin>>t;
    for(int test=0;test<t;test++){
        int MIN=1000000007,MAX=-1;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>l>>r;
            MIN=min(MIN,r);
            MAX=max(MAX,l);
        }
        cout<<max(MAX-MIN,0)<<endl;
    }
}