

    #include <iostream>
    #include <algorithm>
    #include <stdio.h>
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        long long mi=2000000000,ma=0,tot1=0,tot2=0;
        for (int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if (x<mi)
            {
                mi=x;
                tot1=1;
            }
            else if (x==mi)
                tot1++;
            if (x>ma)
            {
                ma=x;
                tot2=1;
            }
            else if (x==ma)
            {
                tot2++;
            }
        }
        if (ma==mi)
        {
            cout<<0<<" "<<tot1*(tot1-1)/2<<endl;
        }
        else
        cout<<ma-mi<<" "<<tot1*tot2<<endl;
    }