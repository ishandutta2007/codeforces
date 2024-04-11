#include<iostream>
#include<vector>
#include<set>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
int main(){
    int n,a=0;
    cin>>n;
    for(int i=1;i<n;i++){
        a=(a+i)%n;
        cout<<(a+1)<<' ';
    }
    return 0;
}