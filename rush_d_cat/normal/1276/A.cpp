#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=150000+10;
int t,n;
char s[N]; bool vis[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e'){
                vis[i+2]=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0&&vis[i+1]==0&&vis[i+2]==0){
                if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')vis[i+1]=1;
                if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')vis[i+1]=1;
            }
        }

        vector<int> v;
        for(int i=1;i<=n;i++)if(vis[i]==1)v.push_back(i);
        printf("%d\n", v.size());
        for(auto x:v)printf("%d ", x);
        printf("\n");
    }
}