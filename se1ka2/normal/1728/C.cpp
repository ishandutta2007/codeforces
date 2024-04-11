#include <iostream>
#include <queue>
using namespace std;

int dig(int x)
{
    int res = 0;
    while(x)
    {
        x /= 10;
        res++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue<int> quea, queb;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            quea.push(a);
        }
        for(int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            queb.push(b);
        }
        int ans = 0;
        while(quea.size())
        {
            int a = quea.top();
            int b = queb.top();
            if(a == b)
            {
                quea.pop();
                queb.pop();
            }
            if(a > b)
            {
                quea.pop();
                quea.push(dig(a));
                ans++;
            }
            if(a < b)
            {
                queb.pop();
                queb.push(dig(b));
                ans++;
            }
        }
        cout << ans << "\n";
    }
}