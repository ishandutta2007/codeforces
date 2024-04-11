#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int s[200005], t[200005];
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        int last = 0;
        for(int i = 0; i < n; i++)
        {
            cout << t[i] - max(last, s[i]) << " ";
            last = t[i];
        }
        cout << endl;
    }
}