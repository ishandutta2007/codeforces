#include<iostream>

using namespace std;

string s[101];
int a[101];

int n,m,res;

void solve(int x)
{
    if(x==m)return;

    int i,j,j2;
    int b[101];
    for(i=0;i<n;i++)b[i]=0;

    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            if(s[i][x]<s[i-1][x])
            {
                res++;
                solve(x+1);
                //cout<<x<<" "<<i<<endl;
                return;
            }
            else
            {
                if(s[i][x]>s[i-1][x])
                {
                    for(j=i;j<n;j++)
                    {
                        b[j]++;
                    }
                }
            }
        }
    }

    for(j2=0;j2<n;j2++)
    {
        a[j2]+=b[j2];
        //cout<<a[j2]<<" "<<j2<<endl;
    }

    solve(x+1);
}

int main ()
{
    int i;

    ios::sync_with_stdio(false);

    cin>>n>>m;

    for(i=0;i<n;i++)cin>>s[i];
    for(i=0;i<n;i++)a[i]=0;

    solve(0);

    cout<<res<<endl;

    return 0;
}