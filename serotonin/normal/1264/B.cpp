#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+5;

int a[5];

int main()
{
    int tot=0;
    for(int i=0; i<4; i++) cin >> a[i], tot+=a[i];

    vector <int> ans;
    int x=min(a[0],a[1]);
    a[0]-=x, a[1]-=x;
    int y=min(a[3],a[2]);
    a[3]-=y, a[2]-=y;
    int z=min(a[1], a[2]);
    a[1]-=z, a[2]-=z;
    for(int i=0; i<x; i++) ans.push_back(0), ans.push_back(1);
    for(int i=0; i<z; i++) ans.push_back(2), ans.push_back(1);
    for(int i=0; i<y; i++) ans.push_back(2), ans.push_back(3);

    if(a[0]) ans.push_back(0);
    if(a[1]) reverse(ans.begin(), ans.end()), ans.push_back(1);
    if(a[2]) ans.push_back(2);
    if(a[3]) reverse(ans.begin(), ans.end()), ans.push_back(3);

    bool ok=ans.size()==tot;
    for(int i=0; i+1<ans.size(); i++) if(abs(ans[i]-ans[i+1])!=1) ok=0;

    if(!ok) puts("NO");
    else {
        puts("YES");
        for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
    }
}