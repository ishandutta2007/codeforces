#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

const ULL magic =   1000007;
const int maxn  =   200005;

int n,m,a[maxn],b[maxn],pos[maxn];
int size[maxn*4];
ULL tree[maxn*4],pw[maxn];

inline void merge(int u,int l,int r)
{
    size[u]=size[l]+size[r];
    tree[u]=tree[l]*pw[size[r]]+tree[r];
}

inline void insert(int num,int l,int r,int pos,int delta,int sign)
{
    if (l==r){
        tree[num]+=delta;
        size[num]+=sign;
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid) insert(num*2,l,mid,pos,delta,sign);
    else insert(num*2+1,mid+1,r,pos,delta,sign);
    merge(num,num*2,num*2+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    ULL h=0,s=0;
    pw[0]=1;
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        h=h*magic+a[i];
        pw[i+1]=pw[i]*magic;
        s+=pw[i];
    }
    for (int i=0;i<m;++i){
        scanf("%d",&b[i]);
        pos[b[i]]=i;
    }
    
    memset(tree,0,sizeof(tree));
    memset(size,0,sizeof(size));
    int cnt=0;
    for (int i=1;i<=m;++i){
        insert(1,0,m-1,pos[i],i,1);
        if (i>n) insert(1,0,m-1,pos[i-n],-(i-n),-1);
        if (i>=n){
            int d=i-n;
            if (tree[1]-d*s==h) ++cnt;
        }
    }
    printf("%d\n",cnt);
    
    return 0;
}