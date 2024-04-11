#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int loc[1000000];
int n;
vector<pair<int,int> > vec;
void Swap(int x,int y)
{
    if (x>y)swap(x,y);
    if (abs(x-y)>=n/2) {
        swap(a[x], a[y]);
        vec.push_back({x,y});
        loc[a[x]] = x;
        loc[a[y]] = y;
    } else if (y<=n/2) {
        Swap(x,n);
        Swap(n,y);
        Swap(x,n);
    } else if (y>n/2 && x>n/2) {
        Swap(x,1);
        Swap(1,y);
        Swap(x,1);
    } else {
        Swap(x,n);
        Swap(n,y);
        Swap(x,n);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),loc[a[i]]=i;
    for (int i=1;i<=n;i++)
    {
        if (i!=a[i])
            Swap(i,loc[i]);
    }
    assert(vec.size()<=n*5);
    printf("%d\n",(int)vec.size());
    for (auto p:vec)
        printf("%d %d\n",p.first,p.second);
}