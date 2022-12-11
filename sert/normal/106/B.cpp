#include <iostream>

using namespace std;

int main()
{
    int a[101], b[101], c[101], p[102], use[101];
    int n, min;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> p[i];
        use[i] = 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] < a[j])
                if (b[i] < b[j])
                    if (c[i] < c[j])
                        use[i] = 1;
    //for (int i = 1; i <= n; i++)cout << use[i] << " ";
    min = n + 1;
    p[n + 1] = 1001;
    for (int i = 1; i <= n; i++)
        if (p[i] < p[min])
        {
         //cout << p[i] << " " << p[min] << " " << use[i] << endl;

            if (use[i] == 0)
                min = i;
        }
    cout << min;
    return 0;
}