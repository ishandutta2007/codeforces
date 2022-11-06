#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

map <int,int> mp;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        int x,ans=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            if(!mp[x]) ans++, mp[x]=1;
        }

        printf("%d\n", ans);
        mp.clear();
    }
}