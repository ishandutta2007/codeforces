#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int a[sz];
map <int,int> mp;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);;
    sort(a,a+n);

    if(n>1 && !a[0] && !a[1]) {
        puts("cslnb");
        return 0;
    }

    for(int i=0; i<n; i++) {
        if(!mp[a[i]]) mp[a[i]]=1;
        else mp[a[i]]++;
    }

    bool shift=0;
    vector <int> ara;
    for(int i=0; i<n; i++) {
        if(mp[a[i]]>1) {
            if(shift || mp[a[i]-1]) {
                puts("cslnb");
                return 0;
            }

            shift=1;
            mp[a[i]]--;
            mp[a[i]-1]=1;
            ara.push_back(a[i]-1);
            continue;
        }
        ara.push_back(a[i]);
    }

    ll posmov=0;
    for(int i=0; i<ara.size(); i++) posmov+=ara[i]-i;
    if(posmov%2==0LL) shift^=1;

    if(shift) puts("cslnb");
    else puts("sjfnb");
}