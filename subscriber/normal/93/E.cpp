#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

long long ans=0,n,zz[10111111];
int k,a[111],kk=0;

long long rec(long long n,int l){
    if (!n)return 0;
    if (l==k)return n;
    long long t=n*100+l;
    if (t<1e7&&zz[t])return zz[t];
    long long r=rec(n,l+1)-rec(n/a[l],l+1);
    if (t<1e7)zz[t]=r;
    return r;
}

int main(){
//  freopen("1.in","r",stdin);  
//  freopen("1.out","w",stdout);    
    cin >> n >> k;
    for (int i=0;i<k;i++)cin >> a[i];
    sort(a,a+k);
    reverse(a,a+k);
    cout << rec(n,0) << endl;
    return 0;
}