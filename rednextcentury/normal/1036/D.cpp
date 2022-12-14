#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr first
#define se second
#define all(v) v.begin(), v.end()
#define loop(n) for(int i = 0; i < n; i++)

const ll oo = 1e16;
using namespace std;

const int N = 300005;
ll a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin>>n;
    loop(n)
    cin>>a[i];
    cin>>m;
    loop(m)
    cin>>b[i];

    ll suma = 0, sumb = 0, res = 0;
    int i = 0, j = 0;
    while(i != n || j != m)
    {
        ///new element
        if(!suma && !sumb){
if (i==n || j==m)break;
            suma = a[i], sumb = b[j], i++, j++;
}
        else if(suma > sumb)
        {
            if(j == m)
                break;
            sumb += b[j], j++;
        }
        else if(suma < sumb)
        {
            if(i == n)
                break;
            suma += a[i], i++;
        }

        ///end of cur element
        if(suma == sumb)
            suma = 0, sumb = 0, res++;

    }

    if(i != n || j != m || suma || sumb)
        res = -1;
    cout<<res;
    return 0;


}