#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int n,m,x,y,x1,y1;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]=='X'){
                x1=i;y1=j;
            }
        }
    }
    for(int i=n-1;i>-1;i--){
        for(int j=m-1;j>-1;j--){
            if (a[i][j]=='X'){
                x=i;y=j;
            }
        }
    }
    string ans="YES";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]=='X'){
                if(i<x || i>x1 || j<y ||j>y1){
                    ans="NO";
                }
            }
            else{
                if((i>=x && i<=x1) && (j>=y && j<=y1)){
                    ans="NO";
                }
            }
        }
    }
    cout<<ans;

    return 0;
}