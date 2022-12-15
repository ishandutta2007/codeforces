#include<iostream>

using namespace std;

int a[101];

int main ()
{
    int n,m,x,y,j2,res,res2=-1,j;

    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        a[x]=y;
    }

    for(int i=1;i<=100;i++)
    {
        //cout<<i<<endl;
        x=0;
        res=-1;
        for(j2=0;x==0;j2++)
        {
            //cout<<j2<<endl;
            for(j=j2*i+1;j<(j2+1)*i+1;j++)
            {
                //cout<<j<<endl;
                if(a[j]!=0 && a[j]!=j2+1)
                {
                    x=1;
                    break;
                }
                if(j==n)res=j2+1;
                if(j==100 && res==-1)
                {
                    cout<<res<<endl;
                    return 0;
                }
                else
                {
                    if(j==100)
                    {
                        if(res2!=-1 && res!=res2)
                        {
                            cout<<"-1"<<endl;
                            return 0;
                        }
                        else res2=res;
                        x=1;
                        break;
                    }
                }
            }
        }
    }

    cout<<res2<<endl;

    return 0;
}