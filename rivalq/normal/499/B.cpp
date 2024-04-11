#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    int n,m,k;
    string t;
    cin>>n>>m;
    string arr1[m];
    string arr2[m];
    for(int i=0;i<m;i++) cin>>arr1[i]>>arr2[i];
    for(int i=0;i<n;i++){
        cin>>t;
        for(int j=0;j<m;j++){
            if(arr1[j]==t||arr2[j]==t) {k=j;break;}
        }
        t=(arr1[k].length()<=arr2[k].length())?arr1[k]:arr2[k];
        cout<<t<<" ";
    }
    cout<<"\n";
}