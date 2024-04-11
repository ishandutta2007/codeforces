#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
   int arr[14]={4,7,44,77,444,777,47,774,447,474,747,74,477,744};
   sort(arr,arr+14);
   int c=0;
   for(int i=0;i<14;i++){
       if(n%arr[i]==0){
           c=1;
           break;
       }
   }
if(c==1){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}

}