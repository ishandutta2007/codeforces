#include<iostream>

using namespace std;

int a[1001];

short boo[1001],boo2[1001];

int main ()
{
    int n,i,x1,x2,y1,y2,p,br=0,j1,j2;

    ios::sync_with_stdio(false);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        boo2[a[i]]++;
    }
    for(i=0;i<n;i++)
    {
        cin>>p;

        boo[p]++;

        if(p!=a[i])
        {
            if(br==0)
            {
                x1=a[i];
                x2=p;
                j1=i;
            }
            else
            {
                y1=a[i];
                y2=p;
                j2=i;
            }
            br++;
        }
    }

    if(br==1)
    {
        for(i=1;i<=n;i++)
        {
            if(boo[i]==0)
            {
                p=i;
                break;
            }
        }

        for(i=0;i<n-1;i++)
        {
            if(i==j1)cout<<p<<" ";
            else cout<<a[i]<<" ";
        }
        if(i==j1)cout<<p<<endl;
        else cout<<a[i]<<endl;

        return 0;
    }

    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<boo[x2]<<" "<<boo2[y1]<<endl;

    if(x2==y1 || (boo[x2]==2 && x2!=y2) || boo[x2]>2 || (boo2[y1]==2 && y1!=x1) || boo2[y1]>2)
    {
        swap(x2,x1);
        swap(y1,y2);
    }

    for(i=0;i<n-1;i++)
    {
        if(i==j1)cout<<x2<<" ";
        else
        {
            if(i==j2)cout<<y1<<" ";
            else cout<<a[i]<<" ";
        }
    }
    if(i==j1)cout<<x2<<endl;
    else
    {
        if(i==j2)cout<<y1<<endl;
        else cout<<a[i]<<endl;
    }

    return 0;
}