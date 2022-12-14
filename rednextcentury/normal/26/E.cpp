#include <bits/stdc++.h>
#define ll long long
using namespace std;
int num[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,w;
    cin>>n>>w;
    int tot=0;
    int mn=1e9;
    int id=-1;
    for (int i=0;i<n;i++)
    {
        cin>>num[i];
        tot+=num[i];
        if (num[i]<mn)mn=num[i],id=i;
    }
    if (w>tot || w<1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if (n==1 && w!=num[0])cout<<"No"<<endl;
    else if (n==1)
    {
        cout<<"Yes"<<endl;
        for (int i=0;i<w*2;i++)
            cout<<1<<' ';
        cout<<endl;
    }
    else
    {
        if (w==1)
        {
            if (mn==1)
            {
                cout<<"Yes"<<endl;
                cout<<id+1<<' ';
                for (int i=0;i<n;i++)
                    for (int j=0;j<num[i]&&i!=id;j++)
                        cout<<i+1<<' '<<i+1<<' ';
                cout<<id+1<<endl;
            }
            else
                cout<<"No"<<endl;
        }
        else
        {

            vector<int> last;
            int rem=tot-w;
            cout<<"Yes"<<endl;
            cout<<1<<' ';
            for (int i=0;i<num[1]-1;i++)
            {
                if (rem)
                {
                    rem--;
                    cout<<"2 2 ";
                }
                else
                    last.push_back(2),last.push_back(2);
            }
            for (int i=2;i<n;i++)
            {
                for (int j=0;j<num[i];j++)
                {
                    if (rem)
                    {
                        rem--;
                        cout<<i+1<<' '<<i+1<<' ';
                    }
                    else
                        last.push_back(i+1),last.push_back(i+1);
                }
            }
            cout<<1<<' '<<2<<' ';
            for (int i=0;i<num[0]-1;i++)
            {
                if (rem)
                {
                    rem--;
                    cout<<"1 1 ";
                }
                else
                    last.push_back(1),last.push_back(1);
            }
            cout<<2<<' ';
            for (auto x:last)cout<<x<<' ';
            cout<<endl;
        }
    }
}