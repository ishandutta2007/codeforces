#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    vector<int> c(0);
  
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(!count(c.begin(),c.end(),t))
        {
            if(c.size()==k){
                c.pop_back();
                }
            c.insert(c.begin(), t);
        }
    }
    int s=c.size();
    cout<<s<<endl;
    for(int i=0;i<s;i++){
        cout<<c[i]<<" ";
    }
}