#include<bits/stdc++.h>
using namespace std;
int islucky(int k){
    k=(k>=0)?k:-k;
    while(k!=0){
        if(k%10==8) return 1;
        k/=10;
    }
    return 0;
}
int main(){
    int n,i=1;
    cin>>n;
    while(!islucky(n+i)){
        i++;
    }
    cout<<i<<endl;
}