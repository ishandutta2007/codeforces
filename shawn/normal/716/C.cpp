#include <bits/stdc++.h>

using namespace std;

#define LL long long

int n;

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            if(i==1)
                printf("2\n");
            else
                cout<<(LL)(i+1)*(i+1)*i-(i-1)<<endl;
        }
    }
    return 0;
}