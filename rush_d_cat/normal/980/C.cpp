#include <iostream>
#include <cstring>
using namespace std;
const int N = 200000+10;

int n,k,a[N];
int group[N], size[N];
int main() {
    scanf("%d%d",&n,&k);
    memset(group,-1,sizeof(group));
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if (group[a[i]] != -1) {
            printf("%d ", group[a[i]]);
            continue;
        }
        int x=a[i];
        while(x>=0 && a[i]-x+1<=k && group[x]==-1) x--;

        if(x < 0 || group[x] == -1) {
            x ++;
            for(int j=x;j<=a[i];j++) 
                group[j] = x, size[x] ++;
            printf("%d ", x);
            continue;
        }

        int cnt=a[i]-x;
        if(size[group[x]]+cnt<=k) {
            for(int j=x+1;j<=a[i];j++)
                group[j]=group[x], size[group[x]]++;
            printf("%d ", group[x]);
        } else {
            for(int j=x+1;j<=a[i];j++)
                group[j]=x+1, size[x+1] ++;
            printf("%d ", x+1);
        }
    }
}