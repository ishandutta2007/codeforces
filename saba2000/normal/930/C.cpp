#include <bits/stdc++.h>
using namespace std;
int a[100009];
int bit[100009];
int n;
void upd(int x,int v){
    while(x<=n)
    {
        //cout << x <<endl;
        if(v>bit[x]) bit[x]=v;
        x+=(x&-x);
    }
}
int fin(int l){
    int ans=0;
    while(l>0)
    {

    //cout << l <<endl;
        if(bit[l]>ans) ans=bit[l];
        l-=(l&-l);
    }
    return ans;
}
int dpl[100009],dpr[100009];
main()
{
    int m;
    cin >>n >>m;
    for (int i=0; i < n; i++)
    {
        int l,r;
       cin >> l >>r;
        a[l] ++;
        a[r+1]--;
    }
    for (int i= 1;  i <= m; i++)
        a[i] += a[i-1];
    for (int i =1; i <= m; i++)
    {
        dpl[i] = fin(a[i]+1) + 1;
        upd(a[i]+1,dpl[i]);
    }
   // cout <<1 << endl;
    for (int i=1; i<= n; i++)
    bit[i]= 0;
    for (int i=m; i>=1; i--)
    {
        dpr[i] = fin(a[i]+1) + 1;
        upd(a[i]+1,dpr[i]);
    }
    int ans=0;
    for (int i=1; i<= m; i++)
        ans=max(ans,dpl[i]+dpr[i]-1);
        cout<<ans<<endl;
}