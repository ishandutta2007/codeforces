#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> >v[200009];
pair<long long,long long> a[200009];
main()
{
    long long n,T;
    cin >> n >> T;
    for (long long i=0; i< n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    long long l =0 , r = n ;

        vector<pair<long long,long long> > v;
    while( l <= r)
    {
        v.clear();
        long long mid = (l+r + 1)/2;
        for (long long i = 0 ; i < n; i++)
            if(a[i] . first >= mid) v.push_back({a[i].second,i});
        sort(v.begin(),v.end());
        if ( l== r) break;
        if (mid > v.size())
        {
            r = mid-1;
            continue;
        }
        long long k =0;
        for (long long i=0; i < mid; i++)
        {
            k += v[i].first;
        }
        if ( k <= T) l = mid;
        else r = mid-1;

    }
    cout << l << endl;
    cout << l << endl;
    for (long long i =0; i < l; i++)
        cout << v[i].second +1 <<" ";
    cout << endl;


}