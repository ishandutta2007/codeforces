#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

string s,s1;
int d[500001][28];

int main()
    {
    int n,k,i,j,h,l=0;
    cin>>n>>k;
    cin>>s;
    int br=0;

    for(i=0;i<k;i++)
    if(s[0]-'A'!=i)d[0][i]++;

    br=s[0]-'A';

    for(i=1;i<n;i++)
        {
        for(j=0;j<k;j++)
            {
            d[i][j]=1000000001;

            if(br!=j)
                {
                l=0;
                if(s[i]!=j+'A')l=1;

                d[i][j]=d[i-1][br]+l;
                }
            else
                {
                for(h=0;h<k;h++)
                    {
                    if(h!=j)
                        {
                        l=0;
                        if(s[i]!=j+'A')l=1;

                        d[i][j]=min(d[i][j],d[i-1][h]+l);
                        }
                    }
                }
            }
        br=0;
        for(j=0;j<k;j++)
        if(d[i][br]>d[i][j])br=j;
        }
    cout<<d[n-1][br]<<endl;
    s1+=br+'A';
    for(i=n-1;i>0;i--)
        {
        for(j=0;j<k;j++)
            {
            l=0;
            if(s[i]!=br+'A')l=1;
            if(j!=br&&d[i-1][j]+l==d[i][br])
                {
                s1+=j+'A';
                br=j;
                break;
                }
            }
        }
    reverse(s1.begin(),s1.end());
    cout<<s1<<endl;

    return 0;
    }