#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=505;
char a[N];
int main(){
    scanf("%s",a+1);int n=strlen(a+1);
    int max='a'-1;
    rep(i,1,n){
        if(a[i]<=max)continue;
        if(a[i]!=max+1){
            puts("NO");
            return 0;
        }
        max+=1;
    }
    puts("YES");
    return 0;
}