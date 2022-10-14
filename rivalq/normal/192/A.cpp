#include<bits/stdc++.h>
using namespace std;
int main(){
   long long  int n;
    cin>>n;
  long long  int k=0,i=1;;
    vector<long long int> v;
    v.push_back(1);
    while(k<=n){
        k=(v[i-1]*(i+2))/i;
        v.push_back(k);
        i++;
    }
    int size=i;
    for(int i=0;i<size;i++){
        k=n-v[i];
        if(binary_search(v.begin(),v.end(),k)){
            cout<<"YES"<<endl;return 0;
        }
    }
    cout<<"NO"<<endl;
     
    

}