#include <iostream>
using namespace std;
const int N=500000+10;
typedef long long LL;
int n,k;
char s[N],t[N];
int main(){
    scanf("%d%d%s%s",&n,&k,s,t);
    LL x=1,ans=0;
    for(int i=0;i<n;i++){
        if(x<=k){
            if(x>=2) {
                x += (x-2);
                if(s[i]=='a'&&t[i]=='b')x+=2;
                else if(s[i]=='b'&&t[i]=='a')x+=0;
                else x++;
            } else {
                if(s[i]!=t[i])x++;
            }
            //printf("x=%lld\n", x);
        }
        ans+=min(x,(LL)k);
    }cout<<ans<<endl;
}