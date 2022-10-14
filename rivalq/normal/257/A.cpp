#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,greater<int>());
    for(int i=0;i<n;i++){
        if(k>=m){cout<<i<<endl;return 0;}
        k+=arr[i]-1;
    }
    if(k>=m){
        cout<<n<<endl;
        return 0;
    }
    cout<<-1<<endl;
}