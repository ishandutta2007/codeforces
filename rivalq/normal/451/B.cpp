#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int arr[n],s_arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s_arr[i]=arr[i];
    }
    sort(s_arr,s_arr+n);
    int s=0,e=n-1;
    for(int i=0;i<n;i++){
       if(arr[i]==s_arr[i]) s++;
       else break;
    }
    for(int i=n-1;i>=0;i--){
       if(arr[i]==s_arr[i]) e--;
       else break;
    }
    if(s>e) {cout<<"yes\n"<<"1 1\n";return 0;}
    for(int i=e;i>=s;i--){
        if(arr[i]!=s_arr[s+e-i]) {
            cout<<"no"<<endl;
            return 0;
        }

    }
  cout<<"yes"<<endl;
  cout<<s+1<<" "<<e+1<<endl;

}