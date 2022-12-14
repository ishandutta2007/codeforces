#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   ll t ;
   cin >>t;
   while (t--){
    ll n ;
    cin >>n ;
    pair<ll,ll>p[n];
    map<ll,ll>m;
    for (int i =0 ; i <n ; i++){
        ll x ;
        cin >>x;
        m[x]++;
    }
    int j =0;
    for(map<ll,ll>::iterator it=m.begin(); it!=m.end() ;it++){
        if (it->second>=2){
          p[j].first = it->first;
          p[j].second = it->second;
          j++;
        }
    }
    ll d1 =1e9, d2 =1 , x1 =0 , y1 =0 , x2 = 0 , y2 =0 ;
    for (int i =0 ; i<j ; i++){
        if (p[i].second>=4){
         ll dnew1 =(2*(p[i].first+p[i].first))*(2*(p[i].first+p[i].first));
         ll dnew2 = (p[i].first*p[i].first);
         ll dnew1s =dnew1 *d2 ;
         ll dnew2s =dnew2 *d2;
         ll d1s = d1*dnew2 ;
         ll d2s = d2 *dnew2 ;
         if (dnew1s  <= d1s){
            x1 =p[i].first;
            y1 =p[i].first ;
            x2 =p[i].first ;
            y2 =p[i].first ;
            d1 =dnew1 ;
            d2 = dnew2 ;

         }

        }

         if (i+1<j){
         ll dnew1 =(2*(p[i].first+p[i+1].first))*(2*(p[i].first+p[i+1].first));
         ll dnew2 = (p[i].first*p[i+1].first);
         ll dnew1s =dnew1 *d2 ;
         ll dnew2s =dnew2 *d2;
         ll d1s = d1*dnew2 ;
         ll d2s = d2 *dnew2 ;
          if (dnew1s  <=d1s){
            x1 =p[i].first;
            y1 =p[i+1].first ;
            x2 =p[i].first ;
            y2 =p[i+1].first ;
            d1=dnew1 ;
            d2 =dnew2 ;

         }
    }
    }
    cout <<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

   }


        return 0;
    }