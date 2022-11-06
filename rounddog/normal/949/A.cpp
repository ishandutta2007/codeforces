#include<bits/stdc++.h>
#define maxn 203040

using namespace std;
char s[maxn];
int n,l,r,p,m,a,b;
vector <int> x[maxn],y[maxn];
bool f[maxn];

int main()
{
    scanf("%s",s); n=strlen(s);
    for (int i=0;i<n;i++)
    {
        if (s[i]=='0') p++; else p--;
    }
    if (p<=0){cout << "-1" << endl;return 0;}
    l=0; r=0; a=0; b=0;
    for (int i=0;i<n;i++)
        if (s[i]=='0') {
            x[a].push_back(i+1);
            a=(a+1)%p;
        }
        else {
            y[b].push_back(i+1);
            b=(b+1)%p;
        }
    for (int i=0;i<p;i++)
        for (int j=0;j<y[i].size();j++)
            if (x[i][j]>y[i][j]||x[i][j+1]<y[i][j]){cout << "-1" << endl;return 0;}
    printf("%d\n",p);
    for (int i=0;i<p;i++)
    {
        printf("%d ",x[i].size()+y[i].size());
        for (int j=0;j<y[i].size();j++)
            printf("%d %d ",x[i][j],y[i][j]);
        printf("%d\n",x[i][x[i].size()-1]);
    }
    return 0;
}