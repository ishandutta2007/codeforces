#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200000 + 10;
int n,m;
char s[N],t[N];
int pos[30][N],tot[30];
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        pos[s[i]-'a'][++tot[s[i]-'a']] = i;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%s",t+1);
        int c[30]={0};
        for(int i=1;t[i];i++){
            c[t[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=max(ans,pos[i][c[i]]);
        }
        printf("%d\n", ans);
    }
}