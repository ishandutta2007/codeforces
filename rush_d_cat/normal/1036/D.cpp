#include <iostream>
using namespace std;
const int N = 300000 + 10;
typedef long long LL;

int n,m;
int a[N],b[N];
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d", &m);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);

    LL s1=0,s2=0,ans=0;
    int p=1;
    for(int i=1;i<=n;i++) {
        s1+=a[i];
        while(p<=m&&s2<s1) s2+=b[p++];
        if(s1==s2) {
            ans++;
        }
    }
    if(s1!=s2||p!=m+1) {
        printf("-1\n"); return 0;
    }
    cout<<ans<<endl;
}