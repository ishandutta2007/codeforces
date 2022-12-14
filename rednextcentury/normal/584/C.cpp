#include <iostream>
# include <string>
using namespace std;
bool dp[200][20][10];
int main()
{
    int n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    int eq=0,no=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]==b[i])
            eq++;
        else
            no++;
    }
    string c="";
    if (no/2 + no%2 > k)
        cout<<-1<<endl;
    else
    {
        int num1=no/2 , num2=no/2;
        k-=no/2+no%2;
        while(k && no>1)
        {
            k--;
            no-=2;
            num1--,num2--;
        }
        for (int i=0;i<n;i++)
        {
            if (a[i]==b[i])
            {
                if (k)
                {
                    char x='a';
                    while(x==a[i] || x==b[i])
                        x++;
                    c+=x;
                    k--;
                }
                else
                    c+=a[i];
            }
            else
            {
                if (num1>0 || num2>0)
                {
                    if (num1>0)
                    {

                        c+=b[i];
                        num1--;
                    }
                    else
                        c+=a[i],num2--;
                }
                else
                {
                    char x='a';
                    while(x==a[i] || x==b[i])
                        x++;
                    c+=x;
                }
            }
        }
    }
    cout<<c<<endl;
}