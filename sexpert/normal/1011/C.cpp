#include <bits/stdc++.h>

using namespace std;

double a[1010], b[1010], x[2010];
double m, t;
int n;

bool valid(double f)
{
    for(int i = 0; i < 2*n; i++)
    {
        f -= (m + f)/x[i];
        if(f < 0) return false;
    }
    return true;
}

double bs(){
    double low = 0.0, hi = 1000000001.0;
    while(hi - low > 1e-8)
    {
        double mid = (low + hi)/2;
        if(valid(mid)) hi = mid;
        else low = mid;
    }
    return hi;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    x[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        x[2*i - 1] = b[i];
        x[2*i] = a[i];
    }
    x[2*n - 1] = b[0];
    //for(auto d : x) cout << d << " ";
    //cout << endl;
    double pex = bs();
    //cout << valid(10.0001) << endl;
    if(valid(pex)) cout << fixed << setprecision(10) << pex;
    else cout << -1;
}