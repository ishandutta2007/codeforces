#include <iostream>
using namespace std;
const int N=1000000+10;
int n,p[N],m[N]; char s[N];
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='(')p[i]=p[i-1]+1; else p[i]=p[i-1]-1;
    }
    m[n]=p[n];
    for(int i=n-1;i>=0;i--)m[i]=min(m[i+1],p[i]);
    int ans=0;
    if(p[n]==2) {
        for(int i=1;i<=n;i++){
            if(p[i]<0) break;
            if(s[i]=='(' && p[i]>=2) {
                if(m[i]==2) ans++;
            }
        }
    }
    if(p[n]==-2) {
        for(int i=1;i<=n;i++){
            if(p[i]<-1) break;
            if(s[i]==')') {
                if(m[i]==-2) ans++;
            }
            if(p[i]==-1) break;
        }
    }
    cout<<ans<<endl;
}