#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n),pos_2(n+1);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        pos_2[temp-1]=i;
    }
    for (int i=1;i<n;i++)
    {
        if (pos_2[a[i]]<pos_2[a[i-1]])
        {
            cout << n-i << endl;
            return 0;
        }
    }
    cout << "0";
    return 0;
}