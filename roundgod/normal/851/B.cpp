#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
typedef long long ll;
ll ax,ay,bx,by,cx,cy;
int main()
{
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&ax,&ay,&bx,&by,&cx,&cy);
    ll ab=(bx-ax)*(bx-ax)+(by-ay)*(by-ay);
    ll bc=(cx-bx)*(cx-bx)+(cy-by)*(cy-by);
    ll ac=(cx-ax)*(cx-ax)+(cy-ay)*(cy-ay);
    if(ab==bc&&ac!=2*(ab+bc)) printf("Yes\n"); else printf("No\n");
    return 0;
}