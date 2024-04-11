#include<bits/stdc++.h>
using namespace std;
int P[500][400];;
int a[3]={-1,1,0};
main()
{
    P[0][0]=1;
    P[1][0]=0;
    P[1][1]=1;
    for (int i=2; i<=200; i++)
    {
        int Fl=0;

        for (int Y=1; Y>=-1;Y--)
            for (int z=-1; z<=1; z+=2)
       {
           if(Fl) continue;
           int x=1;
           int y=Y;
           for (int j=0; j<=200;j++)
           {P[i][j]=0;
           }
           for (int j=0; j<=200;j++)
           {
               P[i][j]+=P[i-1][j]*y;
               P[i][j+1]+=P[i-1][j]*x;
               P[i][j]+=P[i-2][j]*z;
           }
           int fl=0;
           for (int j=0; j<=i; j++)
            {if(P[i][j]>1 || P[i][j]<-1 || j%2!=i%2 && P[i][j]!=0) fl=1;
           // cout<<P[i][j]<<" ";
            }
         //   cout<<endl;
           // cout<<fl<<endl;
           if(fl) continue;
          //  for (int j=0; j<=i; j++)
          //  cout<<P[i][j]<<" ";
           //cout<<endl;
           Fl=1;
          break;
       }

    }
    int n;
    cin>>n;
    cout<<n<<endl;
    for (int i=0; i<=n; i++)
        cout<<P[n][i]<<" ";
        cout<<endl;
    cout<<n-1<<endl;
     for (int i=0; i<=n-1; i++)
        cout<<P[n-1][i]<<" ";
}
/*
x^



*/