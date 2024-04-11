#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int gcd (int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

struct num
{
    int nom;
    int denom;
    num (const int &a, const int &b)
    {
        int g = gcd(abs(a),abs(b));
        nom = a/g;
        denom = b/g;
        if (denom<0)
        {
            nom=-nom;
            denom=-denom;
        }
    }
    friend bool operator<(const num &a ,const num &b)
    {
        return a.nom*b.denom<a.denom*b.nom;
    }
    friend bool operator==(const num &a ,const num &b)
    {
        return a.nom*b.denom==a.denom*b.nom;
    }

};

int main()
{
    int n;
    cin >> n;
    vector <num> a;
    for (int i=0;i<n;i++)
    {
        int k,b;
        cin >> k >> b;
        if (k!=0)
        {
            a.push_back(num(-b,k));
        }
    }
    sort(a.begin(),a.end());
    int ans=0;
    if ((int)a.size()>0) ans=1;
    for (int i=1;i<(int)a.size();i++)
    {
        if (!(a[i]==a[i-1])) ans++;
    }
    cout << ans << endl;
    return 0;
}