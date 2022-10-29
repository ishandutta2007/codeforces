

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int main(){
    int n;scanf("%d",&n);
    int a[n];for(int i=0;i<=n-1;i++)scanf("%d",&a[i]);
    int min=1000000005;
    int count=0;
    vector<int>b;
    for(int i=0;i<=n-1;i++){
        if(a[i]<min){
            min=a[i];
            b.clear();
            b.push_back(i);
            count=1;
        }else if(a[i]==min){
            b.push_back(i);
            count++;
        }
    }
    int dis=1000000005;
    for(int i=0;i<b.size()-1;i++){
        if(b[i+1]-b[i]<dis)dis=b[i+1]-b[i];
    }
    printf("%d",dis);
    
    return 0;
}