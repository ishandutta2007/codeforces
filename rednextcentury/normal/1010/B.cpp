#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(a,b) for (int i = a ; i < b ; i++)
using namespace std ;
ll l, r, n, m;
int a[40] ;
void p ()
{
    l = n +1, r = m ;
    ll x ;
    int i = 0 ;
    ll mid = (l+r)/2 ;
    cout << mid << endl;
    while (cin>>x)
    {
        if (x == 0 )
            return  ;
        else if (x == 1)
        {
            if (a[i%n] == -1)
                r = mid-1;
            else
                l = mid+1 ;
            // mid = (l+r)/2 ;
        }
        else
        {
            if (a[i%n] == -1)
                l = mid+1 ;
            else
                r = mid-1 ;
        }
        mid = (l+r)/2;
        cout << mid <<endl;
        i++ ;

    }

}
int main ()
{
    ios::sync_with_stdio(false) ;

    cin >> m >> n ;
    ll x ;
    for (int i = 0 ; i < n ; i++ )
    {
        cout << i+1 << endl ;
        cin >> x;
        a[i] = x ;
        if (x == 0 )
            return 0 ;
    }

    p() ;


    return 0;



}