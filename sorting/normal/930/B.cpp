#include<iostream>
#include<cstdio>

using namespace std;

long long n;

long long a[28][5002][28];
long long cnt[28];

int main ()
{
    string s;
    long long x,j,y,i,j2,sum=0,sum2=0.0;
    long double res=0.0,d=0.0;

    cin>>s;

    n=s.size();

    for(i=0;i<n;i++)
    {
        x=(long long)s[i]-'a';
        cnt[x]++;
        for(j=0;j<n;j++)
        {
            y=(long long)s[(i+j)%n]-'a';
            a[x][j][y]++;
        }
    }

    for(i=0;i<26;i++)
    {
        d=0;
        for(j=0;j<n;j++)
        {
            sum=0;
            sum2=0;
            for(j2=0;j2<26;j2++)
            {
                if(a[i][j][j2]==1)
                {
                    sum2++;
                }
                sum+=a[i][j][j2];
            }
            //cout<<sum2<<" "<<sum<<endl;
            d=(long double)max(d,(long double)sum2/sum);
            //cout<<d<<endl;
        }
        //cout<<d<<" "<<cnt[i]<<endl;
        //cout<<d*cnt[i]/n<<endl;
        res+=(long double)(d*cnt[i])/n;
        //cout<<res<<endl;
    }


    cout<<res<<endl;
    //printf("%lf\n",res);

    return 0;
}