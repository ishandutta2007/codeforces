#include<bits/stdc++.h>
using namespace std;
int a[10000];
char ret[2][13];
int main()
{
    string s;
    cin>>s;
    int num=0;
    int loc=0;
    char x;
    for (int i=0;i<27;i++)
    {
        if (a[s[i]]!=0)
            x=s[i],num=(i+1)-(a[s[i]])-1,loc=a[s[i]];
        else
            a[s[i]]=i+1;
    }
    if (num==0)
        cout<<"Impossible"<<endl;
    else
    {
        if (num%2)
        {
            int r=13-num/2-1;
            int l=12-num/2;
            int p=1;
            for (int i=loc-1;i>=0;i--)
            {
                if (l<0)
                    l=0,p=0;
                ret[p][l]=s[i];
                if (p==1)l--;
                else l++;
            }
            ret[0][13-num/2-1]=s[loc-1];
            for (int i=0;i<num/2;i++)
                ret[0][13-num/2+i]=s[loc++];
            for (int i=0;i<num/2+1;i++)
                ret[1][12-i]=s[loc++];
            loc++;
            int h=0;
            for (int i=loc;i<27;i++)
            {
                if (h==0)
                    r--;
                else r++;
                if (r<0)
                {
                   h=1;
                   r=0;
                }
                ret[h][r]=s[i];
            }
            for (int j=0;j<2;j++){
            for (int i=0;i<13;i++)
            {
                cout<<ret[j][i];
            }
            cout<<endl;
            }
        }
        else
        {
            int r=13-num/2;
            int l=12-num/2;
            int p=1;
            for (int i=loc-1;i>=0;i--)
            {
                if (l<0)
                    l=0,p=0;
                ret[p][l]=s[i];
                if (p==1)l--;
                else l++;
            }
            ret[0][13-num/2]=s[loc-1];
            for (int i=0;i<num/2;i++)
                ret[0][13-num/2+i]=s[loc++];
            for (int i=0;i<num/2;i++)
                ret[1][12-i]=s[loc++];
            loc++;
            int h=0;
            for (int i=loc;i<27;i++)
            {
                if (h==0)
                    r--;
                else r++;
                if (r<0)
                {
                   h=1;
                   r=0;
                }
                ret[h][r]=s[i];
            }
            for (int j=0;j<2;j++){
            for (int i=0;i<13;i++)
            {
                cout<<ret[j][i];
            }
            cout<<endl;
            }
        }
    }
}