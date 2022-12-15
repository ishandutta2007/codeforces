#include<iostream>
#include<vector>

using namespace std;

bool erat[1000001];
vector<int> v;

int main ()
{
    int x,i,t,j,best=1000000,y,j2;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>x;

    for(i=2;i<=x;i++)
    {
        if(erat[i])continue;
        v.push_back(i);
        //cout<<i<<endl;

        for(j=2*i;j<=x;j+=i)
            erat[j]=1;
    }



    t=x;

    //cout<<v.size()<<endl;

    for(i=v.size()-1;i>=0;i--)
    {
        //cout<<t<<" "<<v[i]<<endl;
        y=v[i];

        if(x%y==0)
        {

            for(j2=max(x-y+1,3);j2<x;j2++)
            {
                y=j2;
                for(j=2;j*j<=y;j++)
                {
                    if(y%j==0)
                    {
                        while(y%j==0)y/=j;
                        t=j;
                    }
                }

                //cout<<j2<<" "<<y<<" "<<t<<endl;

                if(y!=1)
                {
                    if(j2!=y)best=min(best,j2-y+1);
                    else best=min(best,j2);
                }
                else best=min(best,j2-t+1);
            }
            break;
        }
    }

    cout<<best<<endl;

    return 0;
}