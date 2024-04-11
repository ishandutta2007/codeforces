#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=4e5,INF=1e17;

int main()
{
    int i,j,w,h,u1,d1,u2,d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    for(i=h; i; i--) {
        w+=i;
        if(i==d1) w-=u1;
        if(i==d2) w-=u2;
        if(w<0) w=0;
    }
    cout << w;
}