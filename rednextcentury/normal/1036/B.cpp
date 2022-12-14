

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(a,b) for (int i = a ; i < b ; i++)
using namespace std ;

int main ()
{
    ios::sync_with_stdio(false) ;
    int n ;
    cin >> n ;
    while (n--){
        ll l , r , k ;
        cin >> l >> r >> k ;
        if (l+r>k){
            ll res = (l+r)-k;
            if (min(l,r) < res)
                cout << -1 << endl;
            else{
                    l-=res;
                    r-=res ;
                cout << (res+(l-l%2)+(r-r%2)) << endl;
            }
        }
        else{
            ll res = k-(l+r) ;
           // cout << res << " " ;
            if (res%2){
                if (min(l,r) == 0 )
                    cout << -1 << endl;
                else{
                    l-- ;
                    r-- ;
                    res++ ;
                    l+=res ;
                    cout << (1+(l-l%2)+(r-r%2)) << endl;
                }
            }
            else{
                    l+=res ;
                    cout << ((l-l%2)+(r-r%2)) << endl;

            }
        }
    }

    return 0;
}