#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int b,f,p;
        cin>>b>>p>>f;
        int h,c;
        cin>>h>>c;
        int mx=0;
        for (int i=0; i<=p; i++)
        {
            for (int j=0; j<=f; j++)
            {
                if (i*2+j*2>b)
                    break;
                if (h*i+c*j>mx)
                    mx=h*i+c*j;
            }
        }
        cout<<mx<<endl;
    }
}