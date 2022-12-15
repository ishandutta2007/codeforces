#include<iostream>

using namespace std;

int a[100001];
int p[300];
int groups[300],cnt=1;

int main ()
{
    int n,k,i,x,j,mini;

    cin>>n>>k;

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        if(p[a[i]])
        {
            a[i]=groups[p[a[i]]];
        }
        else
        {
            for(j=a[i];j>a[i]-k && j>=0;j--)
            {
                if(p[j])
                    if(groups[p[j]]<=a[i]-k)
                        break;
            }
            j++;
            x=j;
            groups[cnt]=j;
            for(j=a[i];j>=x;j--)
                p[j]=cnt;
            cnt++;
        }
    }

    for(i=0;i<n;i++)
    {
        cout<<groups[p[a[i]]]<<" ";
    }

    cout<<endl;

    return 0;
}