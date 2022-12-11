#include <iostream>
#include <algorithm>
using namespace std;
int q;
int n[100],a[100][100];
int x,num;
int main(){
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n[i];
        num=0;
        for(int j=0;j<n[i];j++){
            cin>>a[i][j];
        }
        while(num+1<n[i]){
            x=num;
            for(int j=num;j<n[i];j++){
                if(a[i][num]>a[i][j]) num=j;
            }
            int t=a[i][num];
            for(int j=num;j>x;j--)a[i][j]=a[i][j-1];
            a[i][x]=t;
            if(x==num)num++;
        }
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<n[i];j++){
            if(j)cout<<" ";
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}