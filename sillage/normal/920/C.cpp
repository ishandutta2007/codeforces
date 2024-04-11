#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200010],n;
char str[200010];
int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    scanf("%s",str+1);
    int last=1;
    for (int i=1; i<n; i++)
        if (str[i]=='0') sort(a+last,a+i+1),last=i+1;
    sort(a+last,a+n+1);
    bool flag=1;
    for (int i=1; i<=n; i++) if (a[i]!=i) flag=0;
    puts(flag?"YES":"NO");
    return 0;
}