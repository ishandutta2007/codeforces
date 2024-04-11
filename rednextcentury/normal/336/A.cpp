# include <iostream>
using namespace std;
int main()
{
    long long x,y;
    long long x1=0,x2=0,y1=0,y2=0;
    cin>>x>>y;
    if (x<0 && y>=0)
    {
         x2=x-y;
         x1=0;
         y2=0;
         y1=-x+y;
    }
    else if (y<0 && x>=0)
    {
    
         x1=x-y;
         x2=0;
         y2=-x+y;
         y1=0;
    }
    else if(x>=0 && y>=0)
    {
        x1=(x)+(y);
        y1=0;
        x2=0;
        y2=(x)+(y);
    }
    else
    {
        x2=(x)+(y);
        y2=0;
        x1=0;
        y1=(x)+(y);
    }
    cout<<x2<<" "<<y2<<" "<<x1<<" "<<y1<<endl;
}