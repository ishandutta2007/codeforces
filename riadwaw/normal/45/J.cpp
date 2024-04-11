#include<stdio.h>
#include<string.h>
#include <string>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include <map>
using namespace std;
int arr[111];
void doArr(int n){
    arr[(n-1)/2-1]=2;
    arr[(n-1)/2]=4;
    arr[(n-1)/2+1]=1;
    arr[(n-1)/2+2]=3;
    for(int i=0;i<(n-1)/2-1;i++)
        arr[i]=n-i*2;
    for(int i=n-1;i>(n-1)/2+2;i--)
        arr[i]=n-1-(n-1-i)*2;
}
int main()
{
    //freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<1;
        return 0;
    }
    if(n*m==2 || n*m==3 || (n==m && n==2)){
        cout<<-1;
        return 0;
    }
    if(n==2 && m==3){
        cout<<"1 6 3\n4 2 5\n";
        return 0;
    }
    if(n==3 && m==2){
        cout<<"1 4\n6 2\n3 5\n";
        return 0;
    }
    if(m==3 && n==3)
    {
        cout<<"5 2 8\n1 7 4\n6 3 9\n";
        return 0;
    }
    if(m==1){
        doArr(n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<'\n';
        return 0;
    }
    if(m==2){
        doArr(n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<' '<<(arr[i]+n)<<'\n';
        return 0;
    }
    if(m==3){
        doArr(n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<' '<<(arr[i]+n)<<' '<<(arr[i]+n+n)<<'\n';
        return 0;
    }
    doArr(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<(arr[j]+m*i)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}