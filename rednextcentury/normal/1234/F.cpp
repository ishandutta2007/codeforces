#include <bits/stdc++.h>
using namespace std;
char inp[2000000];
int first[(1<<21)];
int last[(1<<21)];
int mn[21][(1<<20)];
int cnt[(1<<20)];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    scanf("%s",inp);
    s=inp;
    int n=s.size();
    int mask=0;
    int num=0;
    int tot = (1<<20)-1;
    int ret=0;
    for (int i=0;i<=tot;i++)
        cnt[i]=__builtin_popcount(i);
    for (int i=0;i<=tot;i++)
        for (int j=0;j<=20;j++)
            mn[j][i]=n+1;
    mn[0][0]=-1;
    for (int i=0;i<n;i++)
    {

        mask=0;
        num=0;
        for (int j=i;j>=0;j--) {
            int cur = s[j]-'a';
            if ((1<<cur)&mask)break;
            mask|=(1<<cur);
            num++;
            mn[num][mask]=min(i,mn[num][mask]);
            ret=max(ret,cnt[mask]);
        }
    }
    for (int k=0;k<=20;k++) {
        for (int i=0;i<20;i++){
            for (int j=0;j<=tot;j++){
                if ((1<<i)&j)
                    mn[k][j]=min(mn[k][j],mn[k][j^(1<<i)]);
            }
        }
    }
    for (int i=n-1;i>=0;i--) {
        mask=0;
        num=0;
        for (int j=i;j<n;j++) {
            int cur = s[j]-'a';
            if ((1<<cur)&mask)break;
            mask|=(1<<cur);
            num++;
        int tt=cnt[mask];
        for (int j=20;j>=1;j--) {
            if (mn[j][tot-mask]<i){
                tt+=j;
                break;
            }
        }
        ret=max(ret,tt);
        }
    }
    cout<<ret<<endl;
}