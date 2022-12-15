#include<iostream>
#include<algorithm>

using namespace std;

long long br[10];

int main ()
{
    long long k,n,sum=0,p,i;
    string s;

    cin>>k>>s;

    n=s.size();

    //sort(s,s+n);

    for(i=0;i<n;i++)
    {
        p=(long long)s[i]-'0';
        sum+=p;
        br[p]++;
    }

    if(sum>=k)cout<<"0"<<endl;
    else
    {
        p=0;
        i=0;
        //cout<<sum<<endl;
        while(i<9 && br[i]*(9-i)<=(k-sum))
        {
            sum+=br[i]*(9-i);
            p+=br[i];
            i++;
        }
        //cout<<sum<<endl;
        if(sum!=k)
        {
            p+=(k-sum)/(9-i);
            if((k-sum)%(9-i)!=0)p++;
        }
        cout<<p<<endl;
    }

    return 0;
}