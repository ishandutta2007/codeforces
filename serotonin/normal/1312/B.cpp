#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        sort(a,a+n,greater<int>());
        for(int i=0; i<n; i++) printf("%d ", a[i]);
        puts("");
    }
}