#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    vector <int> a(n),ps(m+1),res(n);
    ps[0]=0;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=1;i<=m;i++)
    {
        int temp;
        cin >> temp;
        ps[i]=ps[i-1]+temp;
    }
    int l=0,r=1;
    for (int i=0;i<n;i++)
    {
        cout << (a[i]+ps[r]-ps[l])%c << " ";
        if (r<m) r++;
        if (i>=n-m) l++;
    }
    return 0;
}