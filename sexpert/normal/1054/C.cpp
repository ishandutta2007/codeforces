#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int l[1010], r[1010], s[1010], a[1010];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i];
    for(int i = 0; i < n; i++)
        cin >> r[i];
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        s[i] = l[i] + r[i];
        mx = max(s[i], mx);
    }
    mx++;
    for(int i = 0; i < n; i++)
        a[i] = mx - s[i];
    for(int i = 0; i < n; i++)
    {
        int lt = 0, rt = 0;
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[i])
                lt++;
        }
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] > a[i])
                rt++;
        }
        if(lt != l[i] || rt != r[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}