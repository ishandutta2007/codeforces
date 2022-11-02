#include <iostream>

using namespace std;
int min (int &a,int &b)
{
    if (a<b) return a; else return b;
}
int main()
{

    int n,m,r;
    cin >> n >> m >> r;
    int d[61][61][61];
    for (int q=0;q<m;q++)
    {
        for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    cin >> d[q][i][j];

        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    d[q][i][j] = min (d[q][i][j], d[q][i][k] + d[q][k][j]);
    }


    int dmin[1001][61][61];



    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            {
                dmin[0][i][j]=10000000;

                for (int p=0;p<m;p++)
                {
                    dmin[0][i][j]=min(dmin[0][i][j],d[p][i][j]);
                }
            }
    }



    for (int q=0;q<1000;q++)
    {

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
              dmin[q+1][i][j]=dmin[q][i][j];

        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    dmin[q+1][i][j] = min (dmin[q+1][i][j], dmin[0][i][k] + dmin[q][k][j]);
    }
    for (int i=0;i<r;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        cout << dmin[z][x-1][y-1] <<endl;
    }
    return 0;
}