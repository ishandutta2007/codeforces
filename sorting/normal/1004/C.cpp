#include<iostream>
#include<set>

using namespace std;

int a[100001];
int last[100001];
int cnt;
int c[100001];
int f[100001];

int main ()
{
    int n,i;
    long long res=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(!c[a[i]])
        {
            cnt++;
            f[a[i]]=i;
        }
        c[a[i]]++;
    }

    for(i=0;i<n;i++)
    {
        if(c[a[i]]==1)
                cnt--;
            c[a[i]]--;
        if(f[a[i]]==i)
        {
            res+=cnt;
            //cout<<a[i]<<"  "<<cnt<<endl;
        }
    }

    cout<<res<<"\n";

    return 0;
}