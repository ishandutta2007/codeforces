#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    char x=arr[0][1];
    char o=arr[0][0];
    if(x!=o){
        for(int i=0;i<n;i++){
            if(arr[i][i]!=o || arr[n-1-i][i]!=o){
                cout<<"NO";
                return 0;
            }
        }
        for(int i=0;i<n/2;i++){
            for(int j=i+1;j<n-1-i;j++){
                if(arr[i][j]!=x||arr[j][i]!=x||arr[n-1-i][j]!=x||arr[j][n-1-i]!=x){
                    cout<<"NO";
                    return 0;
                }
            }
        }
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}