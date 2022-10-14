#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c1=0,c2=0;
    int arr[n][2];
    for(int i=0;i<n;i++){
         int r1,r2;
         cin>>r1>>r2;
         arr[i][0]=r1;arr[i][1]=r2;
         c1+=r1;c2+=r2;
    }
    if(c1%2==0 && c2%2==0) {cout<<0<<endl; return 0;}
    if(c1%2==c2%2){
        for(int i=0;i<n;i++){
            if(arr[i][0]%2!=arr[i][1]%2){
                cout<<1<<endl;
                return 0;
            }
        }
        cout<<-1<<endl;
        return 0;
    }
    cout<<-1<<endl;return 0;
}