#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    float sum=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        sum =sum +t;
    }
    cout<<setprecision(12)<<sum/n<<endl;
    
}