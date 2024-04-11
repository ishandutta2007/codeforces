# include <iostream>
# include <stdio.h>
# include <cstdlib>
# include <set>
using namespace std;
int c_x[10][3];
int c_y[10][3];
int main()
{
    int n=4;
    bool point=0;
    int xs=0,ys=0;
    for (int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if (x1==x2 && y1==y2)
            point=1;
        if (x1==x2)
        {
            c_x[xs][0]=y1,c_x[xs][1]=y2,c_x[xs][2]=x1;
            if (c_x[xs][0]>c_x[xs][1]) swap(c_x[xs][0],c_x[xs][1]);
            xs++;
        }
        if (y1==y2)
        {
            c_y[ys][0]=x1,c_y[ys][1]=x2,c_y[ys][2]=y1;
            if (c_y[ys][0]>c_y[ys][1]) swap(c_y[ys][0],c_y[ys][1]);
            ys++;
        }
    }
    if (point || ys!=2 || xs!=2)
        cout<<"NO"<<endl;
    else
    {
        if (c_x[0][0]!=c_x[1][0] || c_x[0][1]!=c_x[1][1] || c_y[0][0]!=c_y[1][0] || c_y[0][1]!=c_y[1][1] || c_y[0][1]!=max(c_x[0][2],c_x[1][2]) || c_y[0][0]!=min(c_x[0][2],c_x[1][2]) || c_x[0][1]!=max(c_y[0][2],c_y[1][2]) || c_x[0][0]!=min(c_y[0][2],c_y[1][2]))
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}