
#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n,k;
bool check(int mid)
{
    int left=k;
    for (int i=0;i<n;i++)
    {
        int cur=a[i];
        if (left<=0)
            return 1;
        if (cur<mid)continue;
        if(cur/2<mid)
        {
            left--;
            continue;
        }
        int num1 = cur/2;
        int num2 = cur/2+cur%2;
        int hh=2;
        int n1=1,n2=1;
        while(1)
        {

            if (num1%2)swap(num1,num2),swap(n1,n2);
            int nn1=n1*2;
            int nn2;
            hh = ((num1>=mid)?n1:0)+((num2>=mid)?n2:0);
            if (num1==num2)
            {
                nn1=n1*2;
                nn2=n2*2;
            }
            else{
            if (num2%2==0)
                nn2=n2*2;
            else
                nn2=n2,nn1+=n2;
            }
            if (num1>num2)
                num2/=2;
            else
                num2=num2/2+num2%2;
            num1/=2;
            int y=((num1>=mid)?nn1:0)+((num2>=mid)?nn2:0);
            if (y<=n1+n2)
                break;
            n1=nn1,n2=nn2;
        }
        left-=hh;
    }
    return left<=0;
}
int bs(int l,int r)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    cout<<bs(1,10000000)<<endl;
}