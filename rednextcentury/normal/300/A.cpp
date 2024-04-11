# include <iostream>
using namespace std;
struct po
{
int d;
bool p;
};
po a[100];
int main()
{
    int n;
    cin>>n;
    int y=n;
    bool positive=0,negative=0;
    int ansp,ansn;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].d;
        if (a[i].d>0 && positive==0)
        {
            positive=1;
            ansp=a[i].d;
            a[i].p=1;
            y--;
        }
        if (a[i].d<0 && negative==0)
        {
            negative=1;
            ansn=a[i].d;
            a[i].p=1;
            y--;
        }
    }
    if (positive==1)
    {
        cout<<1<<" "<<ansn<<endl;
        cout<<1<<" "<<ansp<<endl;
        cout<<y<<" ";
        for (int i=0;i<n;i++)
        {
            if (a[i].p==0)
            {
                cout<<a[i].d;
                if (i<n-1)
                    cout<<" ";
            }
        
            
        }
        cout<<endl;
    
    }
    else
    {
        int o=0;
        cout<<1<<" "<<ansn<<endl;
        cout<<2<<" ";
        for (int i=0;i<n;i++)
        {
            if (a[i].p==0 && a[i].d<0 && o<2)
            {
                o++;
                a[i].p=1;
                y--;
                cout<<a[i].d;
                if (o<2)
                    cout<<" ";
            }
        }
        cout<<endl;
                cout<<y<<" ";
        for (int i=0;i<n;i++)
        {
            if (a[i].p==0)
            {
                cout<<a[i].d;
                if (i<n-1)
                    cout<<" ";
            }
        
            
        }
        cout<<endl;
    
    
    
    
    }

}