# include <algorithm>
# include <iostream>
using namespace std;
int a[4];
int main ()
{
    int ret=0;
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            int y;
            cin>>y;
            if (y==1)
                ret=abs(i-2)+abs(j-2);
        }
    }
    cout<<ret<<endl;
}