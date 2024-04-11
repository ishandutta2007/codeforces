#include <iostream>
#include <stdio.h>
using namespace std;
struct thetail
{
    int h,wall;
};
char walls[250001][2];
int waterlevel[250001][2];
thetail tail[250001];
int tL=0;
int n,k;
int main()
    {
    int i,j,uk=1,otherwall,thiswall,thish;
    for (i=1;i<=250000;i++)
        {
        waterlevel[i][0]=-1;
        waterlevel[i][1]=-1;
        walls[i][0]='-';
        walls[i][1]='-';
        }
    scanf("%d %d",&n,&k);
    for (i=1;i<=n;i++)
        {
        cin>>walls[i][0];
        }
    for (i=1;i<=n;i++)
        {
        cin>>walls[i][1];
        }
    waterlevel[1][0]=0;
    tail[1].h=1;
    tail[1].wall=0;
    tL=1;
    while (uk<=tL)
        {
        //cout<<"working with "<<tail[uk].h<<" at wall "<<tail[uk].wall<<endl;
        if (tail[uk].wall==1)
        otherwall=0;
        else
        otherwall=1;
        thish=tail[uk].h;
        thiswall=tail[uk].wall;

        if (tail[uk].h>n)
            {
            cout<<"YES"<<endl;
            return 0;
            }
        else
            {
            if ( walls[thish+k][otherwall]=='-' && (waterlevel[thish+k][otherwall]==-1 || waterlevel[thish+k][otherwall]>waterlevel[thish][thiswall]+1) )
                {
                waterlevel[thish+k][otherwall]=waterlevel[thish][thiswall]+1;
                tL++;
                tail[tL].h=thish+k;
                tail[tL].wall=otherwall;
                }
            if ( walls[thish+1][thiswall]=='-' && (waterlevel[thish+1][thiswall]==-1 || waterlevel[thish+1][thiswall]>waterlevel[thish][thiswall]+1) )
                {
                waterlevel[thish+1][thiswall]=waterlevel[thish][thiswall]+1;
                tL++;
                tail[tL].h=thish+1;
                tail[tL].wall=thiswall;
                }
            if ( thish!=1 )
                {
                if ( walls[thish-1][thiswall]=='-' && waterlevel[thish][thiswall]+1<thish-1 && (waterlevel[thish-1][thiswall]==-1 || waterlevel[thish-1][thiswall]>waterlevel[thish][thiswall]+1) )
                    {
                    waterlevel[thish-1][thiswall]=waterlevel[thish][thiswall]+1;
                    tL++;
                    tail[tL].h=thish-1;
                    tail[tL].wall=thiswall;
                    }
                }
            }
        uk++;
        }
    cout<<"NO"<<endl;
    return 0;
    }