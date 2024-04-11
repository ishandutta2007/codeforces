#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 600000 + 10;
int w,n,m,p[13];
int a[N],tmp[N],cnt[N],to3[N];
char s[N];
vector<int> opt[N];
int TwoToThree(int x){
    int ans=0;
    for(int i=0;i<w;i++) if(x>>i&1) ans=ans+p[i];
    return ans;
}
int getAns(int dep,int val) {
    if(dep==w) return cnt[val];
    int ans=0;
    for(auto x: opt[dep])
        ans += getAns(dep+1, val+x);
    return ans;
}
int main() {
    p[0]=1;for(int i=1;i<12;i++)p[i]=p[i-1]*3;
    scanf("%d%d%d",&w,&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); tmp[a[i]]++;
    }
    for(int i=0;i<1<<w;i++) to3[i]=TwoToThree(i);
    for(int i=0;i<1<<w;i++){
        for(int j=0;j<1<<w;j++){
            cnt[to3[i]+to3[j]] += tmp[i] * tmp[j];
        }
    }
    while(m--) {
        scanf("%s",s);
        int len=strlen(s); for(int i=0;i<len;i++) if(i<len-i-1) swap(s[i],s[len-i-1]);
        for(int i=0;i<len;i++) {
            opt[i].clear();
            if(s[i]=='A') {
                opt[i].push_back(0); opt[i].push_back(p[i]);
            }
            if(s[i]=='O') {
                opt[i].push_back(0);
            }
            if(s[i]=='X') {
                opt[i].push_back(0); opt[i].push_back(p[i]<<1);
            }
            if(s[i]=='a') {
                opt[i].push_back(p[i]<<1);
            }
            if(s[i]=='o') {
                opt[i].push_back(p[i]); opt[i].push_back(p[i]<<1);
            }
            if(s[i]=='x') {
                opt[i].push_back(p[i]); 
            }
        }
        printf("%d\n", getAns(0,0));
    }
}