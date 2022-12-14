#include<bits/stdc++.h>
using namespace std;
long long H[1000][2];
vector<int> tree[9000000];
int a[2000005];
#define mid (l+r)/2
#define L x*2
#define R L+1
void build(int x,int l,int r,int dep)
{
    if (l==r)
        tree[x].push_back(a[l]);
    else
    {
        build(L, l, mid,dep+1);
        build(R, mid + 1, r,dep+1);
        int st=tree[L].size()-1;
        for (int i=tree[R].size()-1;i>=0;i--)
        {
            while(st>=0 && tree[R][i]<tree[L][st])st--;
            H[dep][0]+=(int)(tree[R].size()-1)-st;
        }
        st=tree[R].size()-1;
        for (int i=tree[L].size()-1;i>=0;i--)
        {
            while(st>=0 && tree[L][i]<tree[R][st])st--;
            H[dep][1]+=(int)(tree[L].size()-1)-st;
        }
        int i=0,j=0;
        while(i<tree[L].size() && j<tree[R].size())
        {
            if (tree[L][i]<tree[R][j])
                tree[x].push_back(tree[L][i]),i++;
            else
                tree[x].push_back(tree[R][j]),j++;
        }
        while(i<tree[L].size())
            tree[x].push_back(tree[L][i]),i++;
        while(j<tree[R].size())
            tree[x].push_back(tree[R][j]),j++;
    }
}
int main()
{
    int h;
    scanf("%d",&h);
    int n = (1<<h);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n,0);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int q;
        scanf("%d",&q);
        for (int i=h-q;i<=h;i++)
            swap(H[i][0],H[i][1]);
        long long ret=0;
        for (int i=0;i<=h;i++)
            ret+=H[i][0];
        printf("%lld\n",ret);
    }
}