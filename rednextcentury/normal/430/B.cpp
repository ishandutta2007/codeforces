#include <iostream>
#include <map>
#include <string>
# include <stdio.h>
# include <map>
# include <queue>
# include <stack>
# include <vector>
# include <algorithm>
using namespace std;
int a[10000];
int ans=0;
void solve(int i,int n,int x)
{
    int now=0;
    int j=i-1;
    
    int now_c=x,now_num=1;
    while (true)
    {
        bool a1=0;
        bool a2=0;
        if (j>=0)
        {
            if (a[j]==now_c)
            {
                now_num++;
                j--;
                a1=1;
            }
        }
        if (i<n)
        {
            if (a[i]==now_c)
            {
                now_num++;
                i++;
                a2=1;
            }
        }
        if (a1==0 && a2==0)
        {
            if (now_num>=3)
            {
                now+=now_num;
                if (j>=0 || j<n)
                {
                    if (j>=0)
                    {
                        now_c=a[j];
                        now_num=1;
                        j--;
                    }
                    if (i<n)
                    {
                        if (j>=0)
                        {
                            if (now_c!=a[i])
                                break;
                            now_num=2;
                            i++;
                        }
                        else
                        {
                            now_num=1;
                                now_c=a[i];
                                i++;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            else
                break;
        }
        else if (j==-1 && i==n)
        {
            if (now_num>=3)
                now+=now_num;
            break;
        }
    }
    if (now>ans)
        ans=now;
}
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<n;i++)
    {
        if (a[i-1]==a[i] && a[i]==x)
        {
            solve(i,n,x);
        }
    
    }
    cout<<max(ans-1,0)<<endl;
}