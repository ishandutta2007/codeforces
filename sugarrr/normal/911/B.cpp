

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
int min(int a,int b){
    if(a<b)return a;
    else return b;
}

int main(){
    int n,a,b;cin>>n>>a>>b;
    int x,y;
    int ans=0;
    for(x=1;x<=n-1;x++){
        y=n-x;
        int count=min(a/x,b/y);
        if(ans<count)ans=count;
    }
    printf("%d",ans);
    
    return 0;
}