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
    int n , k;
    string s ;
    cin >> n >> k >> s ;
    string ss = s ;
    bool ok = 0 ;
    int d = 1 ;
    while (d<s.length()){
    int j = d , i = 0 ;
    while (j<s.length()){
        if (s[i]!=ss[j])
            break ;
            j++ ;
            i++ ;
    }
    if ( j == n && d!=n ){
        ok =1 ;
        break ;
    }
    else
    if (j == n && d == n && s[n-1] == ss[0]){
        ok =1 ;
        break ;
    }
    d++ ;
    }

    if (!ok){
        k--;
        while (k--){
            ss+=s ;
        }
    }
    else{
        k-- ;
        string res = "" ;
        for ( int i = n-d ; i<n ; i++ )
            res+=s[i] ;
        while (k--){
            ss+=res;
        }
    }
    cout << ss ;

    return 0;

}