#include <bits/stdc++.h>
using namespace std;
int fav[1000000];
int mn[1000000],mx[1000000];
bool isFav[1000000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n,m;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        cin>>fav[i];
        isFav[fav[i]]=1;
    }
    int k;
    cin>>k;
    int tmn=0,tmx=0;
    for (int i=0; i<k; i++)
    {

        string s;
        cin>>s;
        int t;
        int num=0;
        int no=0;
        cin>>t;
        for (int j=0; j<t; j++)
        {
            int h;
            cin>>h;
            if (h==0)
                no++;
            else
                num+=isFav[h];
        }
        mn[i]=min(t-num,n-m);
        mn[i]=t-mn[i];

        mx[i]=min(num+no,m);
        tmn=max(tmn,mn[i]);
        tmx=max(tmx,mx[i]);
    }
    for (int i=0; i<k; i++)
    {
        tmn=-10000,tmx=-10000;
        for (int j=0; j<k; j++)
        {
            if (i==j)continue;

            tmn=max(tmn,mn[j]);
            tmx=max(tmx,mx[j]);
        }
        if (mn[i]>=tmx)cout<<0<<endl;
        else if (mx[i]>=tmn)cout<<2<<endl;
        else cout<<1<<endl;
    }
}