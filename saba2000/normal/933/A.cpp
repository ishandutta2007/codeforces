#include<bits/stdc++.h>
using namespace std;
int M[2009][2009];
int a[2009],oo[2009],tt[2009];
main()
{
    int n;
    cin >> n;
    int o =0, t = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        oo[i]= oo[i-1];
        tt[i]=tt[i-1];

        if(a[i] == 1) o++;
        else t++;
         if(a[i] == 1) oo[i]++;
        else tt[i]++;

    }
    int ans = o;
    for (int i = n - 1; i >= 0; i--)
    {
        int O = 0;
        for (int j = i; j < n; j++)
        {
            M[i][j-i+1]=M[i+1][j-i+1];
            if(a[j]==1) O++;
            M[i][j-i+1]=max(M[i][j-i+1],O);
        }
    } for (int i = n - 1; i >= 0; i--)
    {
        ans = max(ans,oo[i-1]+t-tt[i-1]);
        for (int j = i-1; j >= 0; j--)
        {
            int o1 = M[j][i-j];
            int Oo=oo[j-1]+o1;
            ans =max(ans,Oo + t -(i-Oo));
        }


    }
    cout<<ans<<endl;
}