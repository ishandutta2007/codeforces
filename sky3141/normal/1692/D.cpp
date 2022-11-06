#include <bits/stdc++.h>
using namespace std;
int k[] = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b,d;
        int t = 0;
        char c;
        cin >> a >> c >> b>>d;
        int s = 0;
        s = a * 60 + b;
        int p = s;
        while (true)
        {
            for (int j = 0; j < 16; j++)
            {
                if (p == k[j])
                  { 
                     t++;
                  }
                    
            }
            p+=d;
            if(p>=1440)
            {
                p-=1440;
            }
            if(p==s)
            break;
        }
        cout<<t<<"\n";
    }
    return 0;
}