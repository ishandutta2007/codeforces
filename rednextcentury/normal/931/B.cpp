#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007
const int nmax = 7489 +2;

ll solve (ll n)
{
    ll sum =0;
    for (int i =1 ; i <=n ; i++)
    {
        sum+=i;
    }
    return sum ;
}


int main()
{
    ios_base::sync_with_stdio(0);
    ll n, a, b;
    cin >>n>>a>>b;
    ll l1[n+1],l2[n+1],m[n+1];
    int j =0;
    int k =1;
    for (int i =1 ; i <=n ; i++)
    {
        m[i] = i;
        l1[i]=0;
        l2[i]=0;
    }
    while (n !=2)
    {
        j++;
        k=1;
        for (int i =1; i <=n ; i+=2)
        {
            l1[i]=m[i];
            l2[i]=m[i+1];
            if ((a== l1[i] && b== l2[i] )||(b== l1[i] && a== l2[i] ))
            {

                cout<<j<<endl;
                return 0;
            }
            if (l1[i] == a || l1[i]==b)m[k]=l1[i];
            else if (l2[i]==a || l2[i] == b)m[k]=l2[i];
            else m[k]=l1[i];
            k++;

        }
        n /=2;
    }
    cout <<"Final!"<<endl;

//cout<<setprecision(10)<<fixed<<binary()<<endl;
    return 0;
}