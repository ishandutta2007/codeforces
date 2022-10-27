#include <iostream>
using namespace std;
int n,s[1<<24];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char str[4]; scanf("%s",str);
        int mask=0;
        for(int j=0;j<3;j++)mask|=1<<(str[j]-'a');
        s[mask]++;
    }
    for(int i=0;i<24;i++)for(int j=0;j<1<<24;j++)if(j>>i&1)s[j]+=s[j^(1<<i)];
    long long ans=0;
    for(int i=0;i<1<<24;i++){
        ans=ans^((long long)(n-s[i])*(n-s[i]));
    }
    cout<<ans<<endl;
}