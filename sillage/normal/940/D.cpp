#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int x,a[100010],n;
char b[100010];
bool pd0(int d){
    for (int i=d-1; i>=d-4; i--) if (b[i]!='0') return 0;   
    x=-1e9;
    for (int i=d; i>=d-4; i--) x=max(x,a[i]);
    return 1;
}
bool pd1(int d){
    for (int i=d-1; i>=d-4; i--) if (b[i]!='1') return 0;   
    x=1e9;
    for (int i=d; i>=d-4; i--) x=min(x,a[i]);
    return 1;
}
int main(){
    int l=-1e9,r=1e9;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    scanf("%s",b+1);
    for (int i=5; i<=n; i++){
        if (pd0(i) && b[i]=='1') l=max(x+1,l);
        if (pd1(i) && b[i]=='0') r=min(x-1,r);
    }
    printf("%d %d\n",l,r);
    return 0;
}