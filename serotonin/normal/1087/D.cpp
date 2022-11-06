#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int a[sz];

int main()
{
    int n,i,j;
    double s;
    cin >> n >> s;
    for(i=0; i<n-1; i++) {
        int w,v;
        scanf("%d %d", &w, &v);
        a[w]++;
        a[v]++;
    }
    int c=0;
    for(i=1; i<=n; i++) {
        if(a[i]==1) c++;
    }
    double ans=s/c;
    ans=ans*2;
    printf("%.10f\n", ans);
}