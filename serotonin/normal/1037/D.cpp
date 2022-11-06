#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

set <int> t[sz];
int a[sz],done[sz];

int main()
{
    int i,j,k,x,y,z,n,m,s;
    cin >> n;
    for(i=1;i<n;i++) {
        scanf("%d %d", &x, &y);
        t[x].insert(y);
        t[y].insert(x);
    }
    memset(done, 0, sizeof done);
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    x=0;
    int f=1;
    done[a[0]]=1;
    if(a[0]!=1) {
        f=0;
        goto end;
    }
    for(i=1;i<n;i++) {
        done[a[i]]=1;
        while(t[a[x]].find(a[i])==t[a[x]].end()) {
            set <int> :: iterator itr;
            for(itr=t[a[x]].begin(); itr!=t[a[x]].end(); itr++) {
                if(done[*itr]==0) {
                    f=0;
                    goto end;
                }
            }
            x++;
        }
    }
    end: if(f) puts("Yes");
    else puts("No");
}