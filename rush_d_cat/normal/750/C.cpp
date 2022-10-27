#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int rating = 1e8;
int n, c[200000 + 10], d[200000 + 10];
int sum = 0;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i] >> d[i];
        if(d[i] == 2)
        {
            rating = min(rating, 1899 - sum);
        }
        sum += c[i];
    }
    int ok = 1;
    int tmp = rating;
    for(int i=1;i<=n;i++)
    {
        if(tmp >= 1900 && d[i] == 2) ok = 0;
        if(tmp < 1900 && d[i] == 1) ok = 0;
        tmp += c[i];  
    }
    if(!ok) cout << "Impossible" << endl;
    else if(rating == 1e8) cout << "Infinity" << endl;
    else cout << (rating + sum) << endl;
}