#include<iostream>

using namespace std;

int n;
short a[100001];
int br25,br50;

int main ()
{
    int i;

    ios::sync_with_stdio(false);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<n;i++)
    {
        if(a[i]==25)br25++;
        else
        {
            if(a[i]==50)
            {
                if(br25>=1)br25--;
                else break;
                br50++;
            }
            else
            {
                if(br50>=1)
                {
                    if(br25>=1)
                    {
                        br50--;
                        br25--;
                    }
                    else break;
                }
                else
                {
                    if(br25>=3)br25-=3;
                    else break;
                }
            }

        }
    }


    if(i<n)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    return 0;
}