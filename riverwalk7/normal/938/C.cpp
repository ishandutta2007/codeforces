#include <iostream>
#include <fstream>
using namespace std;
int T, x, m, n, k; bool flag;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>x;
        flag = false;
        if(x==0)
        {
            flag = true;
            cout<<1<<" "<<1<<endl;
        }
        for(int j=1; (j*j)<x; j++)
        {
            if(x%j==0&&(j%2==(x/j)%2))
            {
                m = (x/j+j)/2;
                n = (x/j-j)/2;
                k = m/n;
                if(m/k == n)
                {
                    cout<<m<<" "<<k<<endl;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout<<-1<<endl;
        }
    }
}