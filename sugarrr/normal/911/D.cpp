

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
    int n;cin>>n;
    int a[n];for(int i=0;i<=n-1;i++)scanf("%d",&a[i]);
    long long int ans=0;
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(a[i]>a[j])ans++;
        }
    }
    int check[n+1];
    for(int i=0;i<=n;i++){
        if(((i*(i+1))/2)%2==0)check[i]=0;
        else check[i]=1;
    }
    int m;cin>>m;
    for(int qqq=1;qqq<=m;qqq++){
        int l,r;cin>>l>>r;
        int d=r-l;
        ans+=check[d];
        if(ans%2==0)printf("even\n");
        else printf("odd\n");
    }
    
    
    return 0;
}