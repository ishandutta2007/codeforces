#include<iostream>

using namespace std;

int a[300001];
bool b[300001];
int zero;

int main ()
{
    int n,i;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    zero=n;

    for(i=0;i<=n;i++)
    {
        //cout<<zero<<" zero "<<endl;
        cout<<i-(n-zero)+1<<"\n";
        if(i==n)
            continue;

        b[a[i]]=1;
        if(a[i]==zero)
        {
            zero--;
            while(zero>=1 && b[zero])
                zero--;
        }
    }

    return 0;
}