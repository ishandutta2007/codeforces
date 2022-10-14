#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int k,int n){
     for(int i=0;i<n;i++){
         if(arr[i]==k){
             return i+1;
             }
         }
    }
int main(){
    int n;
    cin>>n;
    int arr[n];
    int t1,t2,t3=0;
    t2=t3;
    t1=t2;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr[i]=t;
       if(t==1) t1++;
       if(t==2) t2++;
       if(t==3) t3++;}
    int w=(t1<t2)?t1:t2;
    w = (w<t3)?w:t3;
    cout<<w<<endl;
    for(int i=0;i<w;i++){
        int x1 = search(arr,1,n);
        int x2 = search(arr,2,n);
        int x3 = search(arr,3,n);
        arr[x1-1]=arr[x2-1]=arr[x3-1]=0;
        cout<<x1<<" "<<x2<<" "<<x3<<endl;
    }


}