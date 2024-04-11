#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    int m,n,a[60][60],sum=0,vi[5],vj[5],use[60][60],rc,fc,x[10000],y[10000],xc,yc;
    char ch;
    cin>>m>>n;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>ch;
            if (ch=='#') a[i][j]=1; else a[i][j]=0;
            sum+=a[i][j];
        }
    }
    if (sum<3)
    {
        cout<<-1<<endl;
        return 0;
    }
    vi[1]=-1;vj[1]=0;
    vi[2]=0;vj[2]=-1;
    vi[3]=0;vj[3]=1;
    vi[4]=1;vj[4]=0;
    for (int i=0;i<m;i++)
      for (int j=0;j<n;j++)
        if (a[i][j]==1)
        {
            memset(use,0,sizeof(use));
            use[i][j]=1;
            rc=1;fc=1;
            if ((i>0)&&(a[i-1][j]==1))
            {
                x[1]=i-1;y[1]=j;use[i-1][j]=1;
            }
            else
              if ((j>0)&&(a[i][j-1]==1))
              {
                  x[1]=i;y[1]=j-1;use[i][j-1]=1;
              }
              else
                if ((i+1<m)&&(a[i+1][j]==1))
                {
                    x[1]=i+1;y[1]=j;use[i+1][j]=1;
                }
                else
                {
                    x[1]=i;y[1]=j+1;use[i][j+1]=1;
                }
            for (;rc<=fc;rc++)
            {
                for (int ic=1;ic<=4;ic++)
                {
                    xc=x[rc]+vi[ic];
                    yc=y[rc]+vj[ic];
                    if ((xc>=0)&&(xc<m)&&(yc>=0)&&(yc<n)&&(use[xc][yc]==0)&&(a[xc][yc]==1))
                    {
                        use[xc][yc]=1;
                        fc++;
                        x[fc]=xc;y[fc]=yc;
                    }
                }
            }
            if (fc!=sum-1)
            {
                cout<<1<<endl;
                return 0;
            }
        }
    cout<<2<<endl;
    return 0;
}